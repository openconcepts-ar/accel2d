# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

from litex.soc.interconnect import wishbone
from litex.soc.interconnect.csr import *
from litex.soc.integration.common import *
from litex.soc.integration.soc_core import SoCMini
from litex.soc.integration.builder import *
from litex.soc.integration.soc import *

from litedram.common import LiteDRAMNativePort


from litex.build.generic_platform import *
from litex.build.sim import SimPlatform

class Accel(Module, AutoCSR):
    def __init__(self, name, arg_desc_layout, with_csr=True):
        self.name = name
        self.args = args = stream.Endpoint(arg_desc_layout)

        self.params = dict(
            # Clk / Rst.
            i_clock = ClockSignal("sys"),
            i_reset = ResetSignal("sys"), # Active High.

            # Run / Done
            i_in_run        = args.valid,
            o_out_done      = args.ready,
        )

        for arg, width in args.description.payload_layout:
          self.params["i_in_"+arg] = args.__getattr__(arg)

        if with_csr:
          self.add_csrs()
          
        
    def add_bus_arg(self, bus):
        adr = Signal(32);

        # Core instance.
        # -----------------
        
        self.params.update(dict(
            # Bus.
            o_out_bus_cyc   = bus.cyc,
            o_out_bus_stb   = bus.stb,
            o_out_bus_adr   = adr,
            o_out_bus_we    = bus.we,
            o_out_bus_dat_w = bus.dat_w,
            o_out_bus_sel   = bus.sel,
            
            i_in_bus_ack    = bus.ack,
            i_in_bus_dat_r  = bus.dat_r,
        ))

        #FIXME: use dict
        if bus.data_width == 256:
          self.comb += bus.adr.eq(adr[5:])
        if bus.data_width == 128:
          self.comb += bus.adr.eq(adr[4:])
        if bus.data_width == 64:
          self.comb += bus.adr.eq(adr[3:])
        if bus.data_width == 32:
          self.comb += bus.adr.eq(adr[2:])


    def add_csrs(self):
        self.run	 = CSRStorage(reset=0)
        self.done	 = CSRStatus()

        self.comb += [
        	self.args.valid.eq(self.run.storage),
        	self.done.status.eq(self.args.ready),
        	]
        
        for arg, width in self.args.description.payload_layout:
          csr = CSRStorage(width, name=arg, reset=0)
          setattr(self, arg, csr)
          self.comb += getattr(self.args, arg).eq(csr.storage)

    def do_finalize(self):
        super().do_finalize()
        self.specials.coreinstance = Instance("M_"+self.name, **self.params)




# Export builder -----------------------------------------------------------------------------------

accel_io = [
    # Clk / Rst
    ("clk", 0, Pins(1)),
    ("rst", 1, Pins(1)),
]



"""   
#FIXME: does't work
class AccelSoc(SoCMini):
    def __init__(self, core):
        platform = SimPlatform("Accel", accel_io)

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("clk"), platform.request("rst"))

        # SoCMini ----------------------------------------------------------------------------------
        SoCMini.__init__(self, platform, clk_freq=int(1e6), nterconnect_register=False)

        # Add core
        self.submodules.accelcore = core #there's need to make a submodule
        self.export_masterbus(core.dma_bus)

    def export_dram(self, port):
        # Expose DRAM native port
        self.platform.add_extension(get_native_user_port_ios("native_port", port.address_width, port.data_width))
        self.comb += connect_native_port(port, self.platform.request("native_port"))

    def export_masterbus(self, mbus):
        self.platform.add_extension(mbus.get_ios(mbus.name))
        wb_pads = self.platform.request(mbus.name)
        self.comb += mbus.connect_to_pads(wb_pads, mode="master")

    # SoC finalization -----------------------------------------------------------------------------
    def do_finalize(self):
        super().do_finalize()

        #export all slaves (including CSRs)
        for sname, bus in self.bus.slaves.items():
            ios = bus.get_ios(sname)
            self.platform.add_extension(ios)
            extpads = self.platform.request(sname)
            self.comb += bus.connect_to_pads(extpads, mode="slave")

        from litex.soc.integration.builder import Builder
        builder  = Builder(self, output_dir=build_dir)
        builder.build(build_name=self.accelcore.name, run=False)
"""   
        
        
class AccelImporterSoC(Module): #TODO: separate in base and derived class
    def __init__(self, corename, csr_base=0, busmaster_type="wishbone", debug=False):
        self.name = corename
        self.csr_base = csr_base
        self.mmap_s = s = wishbone.Interface() #CSR and others
        
        if busmaster_type == "wishbone":
            self.mmap_m = m = wishbone.Interface()
        if busmaster_type == "native":
            self.mmap_m = m = LiteDRAMNativePort("both", address_width=30, data_width=128)

        self.busmaster_type = busmaster_type

        if debug:
            self.sync += If(s.cyc & s.we,
                Display("Slave write at 0x%08X <= %d (ack %d)", s.adr, s.dat_w, s.ack))
            self.sync += If(s.cyc & ~s.we,
                Display("Slave read at 0x%08X => %d (ack %d)", s.adr, s.dat_r, s.ack))
            if busmaster_type == "wishbone":
                self.sync += If(m.cyc & m.we,
                    Display("Master write at 0x%08X <= %d (ack %d)", m.adr, m.dat_w, m.ack))
                self.sync += If(m.cyc & ~m.we,
                   Display("Master read at 0x%08X => %d (ack %d)", m.adr, m.dat_r, m.ack))
            if busmaster_type == "native":
                self.sync += If(m.wdata.valid & m.wdata.we,
                    Display("Master native write at 0x%08X <= %d (ack %d)", m.cmd.addr, m.wdata.data, m.wdata.ready))
                self.sync += If(m.rdata.valid & m.rdata.ready,
                   Display("Master native read at 0x%08X => %d (ack %d)", m.cmd.addr, m.rdata.data, m.rdata.valid))

    def instance_core(self, region):
        mmap_m = self.mmap_m
        mmap_s = self.mmap_s

        assert(mmap_s.data_width == 32)
        #normally maps 0x2000_0000 (CSR at CPU address 0x80000000) to 0 (generated soc CSR address)      
        adr = Signal(30)
        self.comb += adr.eq(mmap_s.adr)
        self.comb += If((mmap_s.adr>=(region.origin//4)) & (mmap_s.adr<((region.origin+region.size)//4)),
            adr.eq(mmap_s.adr-(region.origin-self.csr_base)//4)) 
        
        params = dict(
            # Clk / Rst.
            i_clk = ClockSignal("sys"),
            i_rst = ResetSignal("sys"), # Active High.

            # MMAP slave
            i_mmap_s_adr   = adr, #remapped address
            i_mmap_s_dat_w = mmap_s.dat_w,
            o_mmap_s_dat_r = mmap_s.dat_r,
            i_mmap_s_sel   = mmap_s.sel,
            i_mmap_s_cyc   = mmap_s.cyc,
            i_mmap_s_stb   = mmap_s.stb,
            o_mmap_s_ack   = mmap_s.ack,
            i_mmap_s_we    = mmap_s.we,
            i_mmap_s_cti   = mmap_s.cti,
            i_mmap_s_bte   = mmap_s.bte,
            o_mmap_s_err   = mmap_s.err,
        )

        # MMAP master
        if self.busmaster_type=="wishbone":
            params.update(dict(
                o_mmap_m_adr   = mmap_m.adr,
                o_mmap_m_dat_w = mmap_m.dat_w,
                i_mmap_m_dat_r = mmap_m.dat_r,
                o_mmap_m_sel   = mmap_m.sel,
                o_mmap_m_cyc   = mmap_m.cyc,
                o_mmap_m_stb   = mmap_m.stb,
                i_mmap_m_ack   = mmap_m.ack,
                o_mmap_m_we    = mmap_m.we,
                o_mmap_m_cti   = mmap_m.cti,
                o_mmap_m_bte   = mmap_m.bte,
                i_mmap_m_err   = mmap_m.err,
            ))
        if self.busmaster_type=="native":
            params.update(dict(
                o_mmap_m_cmd_valid   = mmap_m.cmd.valid,
                i_mmap_m_cmd_ready   = mmap_m.cmd.ready,
                o_mmap_m_cmd_we      = mmap_m.cmd.we,
                o_mmap_m_cmd_addr    = mmap_m.cmd.addr,
                o_mmap_m_wdata_valid = mmap_m.wdata.valid,
                i_mmap_m_wdata_ready = mmap_m.wdata.ready,
                o_mmap_m_wdata_we    = mmap_m.wdata.we,
                o_mmap_m_wdata_data  = mmap_m.wdata.data,
                i_mmap_m_rdata_valid = mmap_m.rdata.valid,
                o_mmap_m_rdata_ready = mmap_m.rdata.ready,
                i_mmap_m_rdata_data  = mmap_m.rdata.data,
            ))

        self.specials += Instance(self.name, **params)
        

    def connect_to_soc(self, soc):
        #master
        if self.busmaster_type == "wishbone":
          soc.bus.add_master(master=self.mmap_m)
          
        if self.busmaster_type == "native":
           soc.comb += self.mmap_m.connect(soc.sdram.crossbar.get_port())

        #slave
        region_name = self.name+"_region" #CSR base
        region = soc.bus.alloc_region(region_name, 0x1000, cached=False)
        soc.bus.add_slave(name=self.name+"_slave", slave=self.mmap_s, region=region)
        soc.add_constant(region_name, region.origin)
        soc.platform.add_source(self.name + ".v")
        self.instance_core(region)
    

