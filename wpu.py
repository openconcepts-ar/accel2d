# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

from litex.soc.interconnect import wishbone
from litex.soc.interconnect.csr import *
from litex.soc.integration.common import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.soc import *

from accel import Accel, AccelImporterSoC
import os

# Core wrappers ------------------------------------------------------------------------------------
#TODO: generalize by reading or deducing parameters from a file
#to instance:
#  wpu = WPU(corename, pixel_bus_width = pixel_bus_width, debug=False)

class WPUBase(Accel):
    def __init__(self, name, pixel_bus_width=32, debug=False):
        coord_width = 16
        arg_desc_layout = [
            ("x0",      coord_width),
            ("y0",      coord_width),
            ("x1",      coord_width),
            ("y1",      coord_width),
            ("rgba",    32),
            ("base",    32),
            ("xstride", coord_width),
            ("ystride", coord_width),
        ]

        super().__init__(name, arg_desc_layout)
        self.dma_bus = wishbone.Interface(pixel_bus_width)
        self.add_bus_arg(self.dma_bus)
        
          
        if debug:
          adr = Signal(32)
          self.comb += adr[2:].eq(self.dma_bus.adr)
          self.sync += If(self.args.valid & ~self.args.ready & self.dma_bus.we & self.dma_bus.ack,
              Display("x0 %d, y0 %d, dma_addr 0x%08X (0x%08X) done %d", self.args.x0, self.args.y0, self.dma_bus.adr, adr, self.args.ready))

    def connect_to_soc(self, soc):
        soc.bus.add_master(master=self.dma_bus, name="dma_bus_"+self.name)


# Core adder ---------------------------------------------------------------------------------------

def gen_accel_cores(soc, active_cores, pixel_bus_width=32):
    for core in active_cores:
        corename = "accel_" + core
        fb_offset = 0xC00000
        
        #indirect instancing
        wpu = AccelImporterSoC(corename, csr_base=0, busmaster_type="native", debug=False) #importer
        wpu.connect_to_soc(soc)
        setattr(soc.submodules, corename, wpu)

        vram_origin = soc.bus.regions["main_ram"].origin # usually 0x40000000
        soc.add_constant("VRAM_ORIGIN_"+corename, vram_origin + fb_offset)
        soc.platform.add_source(f"{corename}.v")
        soc.platform.add_source(f"{core}.v")



