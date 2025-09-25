# Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

# code portions from LiteX framework (C) Enjoy-Digital https://github.com/enjoy-digital/litex

from migen import *
from litex.soc.interconnect import wishbone
from litedram.frontend.wishbone import LiteDRAMWishbone2Native

#adapts Wishbone slave to native slave
def wb_to_native_adapter(wb_mbus, native_port):
	litedram_wb = wishbone.Interface(data_width=native_port.data_width)

	wb2native = LiteDRAMWishbone2Native(
		wishbone     = wb_mbus,
		port         = native_port,
		base_address = 0)
		
	return wb2native


#this Cache implementation is based on https://github.com/enjoy-digital/litex/blob/master/litex/soc/interconnect/wishbone.py#L553
from migen.fhdl.bitcontainer import log2_int
from migen.genlib.misc import split, displacer, chooser
from migen.genlib.fsm import FSM, NextState, NextValue
from migen.genlib.record import layout_len
from migen.fhdl.specials import Memory

class WriteBackCache(Module):
    """Cache

    This module is a write-back wishbone cache that can be used as a L2 cache.
    Cachesize (in 32-bit words) is the size of the data store and must be a power of 2
    """
    def __init__(self, cachesize, master, slave, reverse=True, skip_reads=False, debug=False):
        self.master = master
        self.slave = slave


        dw_from = len(master.dat_r)
        dw_to = len(slave.dat_r)
        if dw_to > dw_from and (dw_to % dw_from) != 0:
            raise ValueError("Slave data width must be a multiple of {dw}".format(dw=dw_from))
        if dw_to < dw_from and (dw_from % dw_to) != 0:
            raise ValueError("Master data width must be a multiple of {dw}".format(dw=dw_to))

        # Split address:
        # TAG | LINE NUMBER | LINE OFFSET
        offsetbits = log2_int(max(dw_to//dw_from, 1))
        addressbits = len(slave.adr) + offsetbits
        linebits = log2_int(cachesize) - offsetbits
        tagbits = addressbits - linebits
        wordbits = log2_int(max(dw_from//dw_to, 1))
        adr_offset, adr_line, adr_tag = split(master.adr, offsetbits, linebits, tagbits)
        word = Signal(wordbits) if wordbits else None

        # Data memory
        data_mem = Memory(dw_to*2**wordbits, 2**linebits)
        data_port = data_mem.get_port(write_capable=True, we_granularity=8)
        self.specials += data_mem, data_port

        # Byte selection memory
        sel_mem = Memory(len(slave.sel), 2**linebits)
        sel_port = sel_mem.get_port(write_capable=True)
        self.specials += sel_mem, sel_port

        write_from_slave = Signal()
        if adr_offset is None:
            adr_offset_r = None
        else:
            adr_offset_r = Signal(offsetbits, reset_less=True)
            self.sync += adr_offset_r.eq(adr_offset)


        # Tag memory
        tag_layout = [("tag", tagbits), ("dirty", 1)] #TODO: dirty could track the selected bits
        tag_mem = Memory(layout_len(tag_layout), 2**linebits)
        tag_port = tag_mem.get_port(write_capable=True)
        self.specials += tag_mem, tag_port
        tag_do = Record(tag_layout)
        tag_di = Record(tag_layout)
        self.comb += [
            tag_do.raw_bits().eq(tag_port.dat_r),
            tag_port.dat_w.eq(tag_di.raw_bits())
        ]

        self.comb += [
            tag_port.adr.eq(adr_line),
            tag_di.tag.eq(adr_tag)
        ]

        # slave word computation, word_clr and word_inc will be simplified
        # at synthesis when wordbits=0
        word_clr = Signal()
        word_inc = Signal()
        if word is not None:
            self.sync += \
                If(word_clr,
                    word.eq(0),
                ).Elif(word_inc,
                    word.eq(word+1)
                )

        # Data & selection memory logic
        def word_is_last(word):
            if word is not None:
                return word == 2**wordbits-1
            else:
                return 1


        self.comb += [
            data_port.adr.eq(adr_line),
            sel_port.adr.eq(adr_line),
            sel_port.we.eq(0), #TODO: needed?
            If(write_from_slave,
                displacer(slave.dat_r, word, data_port.dat_w),
                displacer(Replicate(1, dw_to//8), word, data_port.we),
            ).Else(
                data_port.dat_w.eq(Replicate(master.dat_w, max(dw_to//dw_from, 1))),
                If(master.cyc & master.stb & master.we & master.ack, #write from master
                    displacer(master.sel, adr_offset, data_port.we, 2**offsetbits, reverse=reverse),
                )
            ),
            chooser(data_port.dat_r, word, slave.dat_w),
            chooser(data_port.dat_r, adr_offset_r, master.dat_r, reverse=reverse)
        ]
        
        first_state = "TEST_HIT" if skip_reads else "REFILL"
        autoevict_counter = Signal(len(adr_line))
        self.submodules.fsm = fsm = FSM(reset_state="TEST_HIT")
        fsm.act("IDLE", #IDLE state not needed, logic moved to TEST_HIT state
            If(master.cyc,
                NextState("TEST_HIT")
            ).Else
            (
                adr_line.eq(autoevict_counter), tag_port.adr.eq(adr_line), data_port.adr.eq(adr_line), sel_port.adr.eq(adr_line), #TODO: needed?
                NextState("AUTO_EVICT")
            )
        )
        fsm.act("TEST_HIT",
          If(master.cyc & master.stb,
            word_clr.eq(1),
            NextValue(autoevict_counter, adr_tag^(2**(linebits-1))), #this is to avoid trying to automatically evict current location
            If(tag_do.tag == adr_tag,
                master.ack.eq(1),
                If(master.we,
                    tag_di.dirty.eq(1),
                    tag_port.we.eq(1), sel_port.we.eq(1), sel_port.dat_w.eq(master.sel | sel_port.dat_r), #selection bits are ORed each time
                ),
            ).Else(
                If(tag_do.dirty,
                    NextState("EVICT")
                ).Else(
                    # Write the tag first to set the slave address
                    tag_port.we.eq(1), sel_port.we.eq(1), If(master.we, sel_port.dat_w.eq(master.sel)).Else(sel_port.dat_w.eq(0)),
                    word_clr.eq(1),
                    NextState(first_state)
                )
            )
          ).Elif(~master.cyc,
                NextState("IDLE")
          )
        )

        fsm.act("EVICT",
            slave.stb.eq(1),
            slave.cyc.eq(1),
            slave.we.eq(1),
            If(slave.ack,
                word_inc.eq(1),
                 If(word_is_last(word),
                    # Write the tag first to set the slave address
                    tag_port.we.eq(1), sel_port.we.eq(1), sel_port.dat_w.eq(0),
                    word_clr.eq(1),
                    NextState(first_state)
                )
            )
        )
        auto_evict = Signal()
        fsm.act("AUTO_EVICT",
            adr_line.eq(autoevict_counter), tag_port.adr.eq(adr_line), data_port.adr.eq(adr_line), sel_port.adr.eq(adr_line),
            auto_evict.eq(tag_do.dirty),
            If(auto_evict,
                slave.cyc.eq(1),
                slave.stb.eq(1),
                slave.we.eq(1),
                If(slave.ack,
                    tag_di.tag.eq(tag_do.tag), #keep tag
                    tag_di.dirty.eq(0), #except dirty
                    tag_port.we.eq(1), sel_port.we.eq(1), sel_port.dat_w.eq(0),

                    NextValue(autoevict_counter, autoevict_counter+1),
                    NextState("IDLE")
                ),
            ).Else(NextState("IDLE"))
        )

        if debug:
            xtag = Signal(tagbits)
            xtag.eq(tag_do.tag)
            adr = Signal(len(slave.adr))
            adr.eq(Cat(adr_line, tag_do.tag))
            self.sync += If(auto_evict,
                Display("AUTO_EVICT line %d, tag 0x%08X, addr 0x%08X, sel 0x%04X, data 0x%032X", autoevict_counter, xtag, adr, sel_port.dat_r, data_port.dat_r)
              )


        fsm.act("REFILL", #TODO: avoid refill if only writings
            slave.stb.eq(1),
            slave.cyc.eq(1),
            slave.we.eq(0),
            If(slave.ack,
                write_from_slave.eq(1),
                word_inc.eq(1),
                If(word_is_last(word),
                    NextState("TEST_HIT"),
                ).Else(
                    NextState(first_state)
                )
            )
        )

        if word is not None:
            self.comb += slave.adr.eq(Cat(word, adr_line, tag_do.tag))
        else:
            self.comb += slave.adr.eq(Cat(adr_line, tag_do.tag))

        self.comb += slave.sel.eq(sel_port.dat_r)



class ConverterWriteCache(Module):
  def __init__(self, master, slave, write_back=True, wb_skip_reads=True, debug=False):
    assert(master.data_width == slave.data_width) #if it works with different sizes should be tested
   
    if debug:
      self.sync += If(slave.cyc & slave.stb & slave.we,
        Display("DST WRITE addr 0x%08X (data 0x%032X, sel 0x%04X) ack %d", slave.adr, slave.dat_w, slave.sel, slave.ack))

      self.sync += If(slave.cyc & slave.stb & ~slave.we,
        Display("DST READ addr 0x%08X (data 0x%032X) ack %d", slave.adr, slave.dat_r, slave.ack))

      self.sync += If(master.cyc & master.stb & master.we,
        Display("SRC WRITE addr 0x%08X (data 0x%032X, sel 0x%04X) ack %d", master.adr, master.dat_w, master.sel, master.ack))

      self.sync += If(master.cyc & master.stb & ~master.we,
        Display("SRC READ addr 0x%08X (data 0x%032X) ack %d", master.adr, master.dat_r, master.ack))

    slave_tmp = wishbone.Interface(data_width=slave.data_width)
    if write_back:
    	self.submodules.cache = WriteBackCache(32, master=master, slave=slave_tmp, reverse=False, skip_reads=wb_skip_reads)
    else:
    	self.submodules.cache = wishbone.Cache(32, master=master, slave=slave_tmp, reverse=False)
    self.comb += slave_tmp.connect(slave) #new usage is master.connect(slave)


def connect_accel_to_native_wbcache(wpu, port):
	bus = wishbone.Interface(port.data_width)
	busx = wishbone.Interface(port.data_width)
	dma_bus = wpu.dma_bus
	wb_cnv = wishbone.Converter(master=dma_bus, slave=busx) #adapts width prior to cache
	wpu.submodules.wb_cnv = wb_cnv
	
	cache = ConverterWriteCache(busx, bus, write_back=True, wb_skip_reads=True) 
	wpu.submodules.cache = cache

	s1 = wb_to_native_adapter(bus, port)
	wpu.submodules += s1

def connect_accel_to_native(wpu, port):
	bus = wpu.dma_bus
	s1 = wb_to_native_adapter(bus, port)
	wpu.submodules += s1

def connect_accel_wbcache(wpu):
	dma_bus= wpu.dma_bus
	bus = wishbone.Interface(dma_bus.data_width)
	cache = ConverterWriteCache(dma_bus, bus) 
	wpu.submodules.cache = cache
	return bus


def gen_accel_cores(soc, active_cores, pixel_bus_width=32):
    for core in active_cores:
        corename = "accel_" + core
        fb_offset = 0xC00000
        
        #direct instancing
        from wpu import WPUBase
        wpu = WPUBase(corename)
        setattr(soc.submodules, corename, wpu)

        vram_origin = soc.bus.regions["main_ram"].origin # usually 0x40000000
        soc.add_constant("VRAM_ORIGIN_"+corename, vram_origin + fb_offset)
        soc.platform.add_source(f"{core}.v")
        
        region_name = corename+"_region" #CSR base
        region = soc.bus.alloc_region(region_name, 0x1000, cached=False)
        soc.add_constant(region_name, region.origin)
        
       	connect_accel_to_native(wpu, soc.sdram.crossbar.get_port(mode="both", data_width=128))


