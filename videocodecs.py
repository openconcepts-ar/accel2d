# Copyright (c) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>

from migen import *
from litex.soc.integration.soc import AutoCSR, CSRStorage, CSRStatus
from litedram.frontend.dma import LiteDRAMDMAWriter
from litedram.frontend.dma import LiteDRAMDMAReader

class JPEGDecoder(Module, AutoCSR):
    def __init__(self, rdport, wrport, DHT=True, output_alpha=0xFF, debug=False):
        assert(rdport.data_width == 32)
        assert(wrport.data_width == 32)

        self.submodules.reader = reader = LiteDRAMDMAReader(rdport, with_csr=True)
        self.submodules.writer = writer = LiteDRAMDMAWriter(wrport, with_csr=False)
        source = self.reader.source

        self.writer_base = CSRStorage(wrport.address_width)
        self.writer_stride = CSRStorage(16)
        self.idle_status = CSRStatus()
        self.outport_width = CSRStatus(16)
        self.outport_height = CSRStatus(16)
        self.outport_x = CSRStatus(16)
        self.outport_y = CSRStatus(16)
        self.outport_pixel_offset = CSRStatus(wrport.address_width)
        pixel_offset = self.outport_pixel_offset.status 

        inport_accept = Signal()
        inport_ready = Signal()
        output_idle = Signal()
        outport_valid = Signal()
        outport_pixel_x = self.outport_x.status
        outport_pixel_y = self.outport_y.status
        outport_pixel_r = Signal(8)
        outport_pixel_g = Signal(8)
        outport_pixel_b = Signal(8)
        alpha_value = Constant(output_alpha)

        self.done = Signal(reset=1)
        out_done = Signal(reset=0)
        reader_last = Signal(reset=0)
        self.sync += If(reader._enable.re & reader.enable & self.done, reader_last.eq(0), out_done.eq(0), self.done.eq(0), Display("start"))
        self.sync += If(reader._enable.re & reader.enable, reader_last.eq(0))
        self.sync += If(reader._done.status & ~reader_last, reader_last.eq(1), Display("_offset %x, _length %x", reader._offset.status, reader._length.storage))
        self.sync += If(reader_last & ~output_idle & ~out_done, out_done.eq(1), Display("out_done %d, %d", outport_pixel_x, outport_pixel_y))
        
        #self.sync += If(out_done & ~self.done, Display("END %d, %d, valid %d", outport_pixel_x, outport_pixel_y, outport_valid))
        self.sync += If(out_done & ~self.done & (outport_pixel_x >= self.outport_width.status-1) & (outport_pixel_y >= self.outport_height.status-1), self.done.eq(~outport_valid), 
         Display("Done at pixel %d,%d, wxh %d, %d, level %d, valid %d", outport_pixel_x, outport_pixel_y, self.outport_width.status, self.outport_height.status, writer.fifo.level, outport_valid))

        self.params = dict(
            p_SUPPORT_WRITABLE_DHT = 1 if DHT else 0,
            i_clk_i = ClockSignal("sys"),
            i_rst_i =  ~reader.enable | ResetSignal("sys"),
            o_outport_width_o = self.outport_width.status,
            o_outport_height_o = self.outport_height.status,
            o_inport_accept_o = inport_accept, #ready to accept data (asserted once each 4 bytes)
            o_idle_o = output_idle, # useful to know when it's done
            i_inport_valid_i = source.valid,
            i_inport_data_i = source.data,
            i_inport_last_i = Constant(0),
            i_inport_strb_i = Constant(0xF),
            i_outport_accept_i = writer.sink.ready,
            o_outport_valid_o = outport_valid,
            o_outport_pixel_x_o = outport_pixel_x,
            o_outport_pixel_y_o = outport_pixel_y,
            o_outport_pixel_r_o = outport_pixel_r,
            o_outport_pixel_g_o = outport_pixel_g,
            o_outport_pixel_b_o = outport_pixel_b,
        )

        self.comb += [
            writer.sink.valid.eq(outport_valid), #write strobe
            pixel_offset.eq(outport_pixel_x + outport_pixel_y * self.writer_stride.storage[2:]),
            writer.sink.address.eq(self.writer_base.storage[2:] + pixel_offset),
            writer.sink.data.eq(Cat(outport_pixel_r, outport_pixel_g, outport_pixel_b, alpha_value)),
            inport_ready.eq(inport_accept | (reader.enable & (reader._offset.status == Constant(0)) )),
            source.ready.eq(inport_ready),
            self.idle_status.status.eq((self.done & writer.fifo.level==0) | ~reader.enable),
        ]

        self.specials += Instance("jpeg_core", **self.params)

