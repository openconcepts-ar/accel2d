# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

# code portions from LiteX framework (C) Enjoy-Digital https://github.com/enjoy-digital/litex

import sys
import argparse

from wpu import gen_accel_cores

from migen import *
from litex.soc.cores.clock import *
from litex.soc.cores.video import VideoTimingGenerator, video_data_layout, video_timings
from litex.soc.interconnect import stream, wishbone
from litex.soc.interconnect.csr import AutoCSR, CSRStorage, CSRStatus
from litex.soc.integration.builder import *
from litex.soc.integration.soc_core import *
from litex.build.generic_platform import *

from litex_boards.platforms import digilent_arty



class VideoGenericPHY_SDR(Module):
    def __init__(self, pads, clock_domain="sys"):
        self.sink = sink = stream.Endpoint(video_data_layout)

        # # #

        # Always ack Sink, no backpressure.
        self.comb += sink.ready.eq(1)

        # Drive Clk.
        if hasattr(pads, "clk"):
            self.comb += pads.clk.eq(ClockSignal(clock_domain))

        # Drive Controls.
        if hasattr(pads, "de"):
            self.comb += pads.de.eq(sink.de)

        if hasattr(pads, "hsync_n"):
            self.comb += pads.hsync.eq(~sink.hsync)
        else:
            self.comb += pads.hsync.eq(sink.hsync)

        if hasattr(pads, "vsync_n"):
            self.comb += pads.vsync.eq(~sink.vsync)
        else:
            self.comb += pads.vsync.eq(sink.vsync)

        # Drive Datas.
        cbits  = len(pads.r)
        cshift = (8 - cbits)
        for i in range(cbits):
            self.comb += pads.r[i].eq(sink.r[cshift + i] & sink.de)
            self.comb += pads.g[i].eq(sink.g[cshift + i] & sink.de)
            self.comb += pads.b[i].eq(sink.b[cshift + i] & sink.de)


class _CRG(Module):
    def __init__(self, platform, sys_clk_freq, video_clock, with_dram):
        self.rst = Signal()
        self.clock_domains.cd_sys = ClockDomain()

        self.submodules.pll = pll = S7PLL(speedgrade=-1)
        rst    = ~platform.request("cpu_reset")
        self.comb += pll.reset.eq(rst | self.rst)
        pll.register_clkin(platform.request("clk100"), 100e6)
        pll.create_clkout(self.cd_sys, sys_clk_freq)

        self.clock_domains.cd_vga= ClockDomain(reset_less=False) #TODO: check why True brings errors
        pll.create_clkout(self.cd_vga, video_clock)
        platform.add_false_path_constraints(self.cd_sys.clk, pll.clkin) # Ignore sys_clk to pll.clkin path created by SoC's rst.

        if with_dram:
            self.clock_domains.cd_sys4x     = ClockDomain()
            self.clock_domains.cd_sys4x_dqs = ClockDomain()
            self.clock_domains.cd_idelay    = ClockDomain()
            pll.create_clkout(self.cd_sys4x,     4*sys_clk_freq)
            pll.create_clkout(self.cd_sys4x_dqs, 4*sys_clk_freq, phase=90)
            pll.create_clkout(self.cd_idelay,    200e6)
            self.submodules.idelayctrl = S7IDELAYCTRL(self.cd_idelay)



def build_arty(args, pixel_bus_width=32, with_video_framebuffer=True, no_compile_gateware=False):
	timings_sel = "640x480@60Hz"
	timings = video_timings[timings_sel]
	timings["pix_clk"] = 25e6 #fix default of 25.18MHz
	
	#supported toolchains: "yosys+nextpnr" or "vivado"
	platform = digilent_arty.Platform(variant="a7-35", toolchain=args.toolchain)

	sys_clk_freq = int(100e6)
	soc = SoCCore(platform, sys_clk_freq, **soc_core_argdict(args))
	soc.submodules.crg = _CRG(platform, sys_clk_freq, timings["pix_clk"], True)

	if args.toolchain == "yosys+nextpnr":
		#this is needed to avoid the unsupported clocked DSP48E1s
		platform.toolchain._yosys_cmds.append("scratchpad -set xilinx_dsp.multonly 1")

		#bram is needed, and abc9 doesn't work
		platform.toolchain._synth_opts = "-flatten -arch xc7 -nowidelut"
		
		#prjxray-db doesn't have xc7a35ticsg324-1L - use closest replacement
		device = "xc7a35tcsg324-1" if platform.device == "xc7a35ticsg324-1L" else platform.device
		
		#packer isn't a python script
		platform.toolchain._pre_packer_cmd = ["fasm2frames"]
		platform.toolchain._pre_packer_opts["fasm2frames"]=" ".join([
			"--part", device,
			"--db-root", "/usr/share/nextpnr/prjxray-db/artix7 digilent_arty.fasm",
			"> digilent_arty.frames"
			])

	# DDR3 SDRAM -------------------------------------------------------------------------------
	if with_video_framebuffer:
		from litedram.modules import MT41K128M16
		from litedram.phy import s7ddrphy
		soc.ddrphy = s7ddrphy.A7DDRPHY(platform.request("ddram"),
            memtype        = "DDR3",
            nphases        = 4,
            sys_clk_freq   = sys_clk_freq)
		soc.add_sdram("sdram",
            phy           = soc.ddrphy,
            module        = MT41K128M16(sys_clk_freq, "1:4"),
            l2_cache_size = 8192
		)

	# Video -------------------------------------------------------------------------------------
	if with_video_framebuffer:
		platform.add_extension([("vga", 0, #PMOD VGA on pmod B & C
			Subsignal("hsync", Pins("U14")), #pmodc.4
			Subsignal("vsync", Pins("V14")), #pmodc.5
			Subsignal("r", Pins("E15 E16 D15 C15")), #pmodb.0-3
			Subsignal("g", Pins("U12 V12 V10 V11")), #pmodc.0-3
			Subsignal("b", Pins("J17 J18 K15 J15")), #pmodb.4-7
			IOStandard("LVCMOS33"))])
			
		soc.submodules.videophy = VideoGenericPHY_SDR(platform.request("vga"), clock_domain="vga")
		soc.add_video_framebuffer(phy=soc.videophy, timings=timings_sel, clock_domain="vga", format="rgb888")

		corelist = ["rectangle_fill32", "ellipse_fill32"]
		gen_accel_cores(soc, corelist, pixel_bus_width)

		soc.add_constant("SDRAM_BUS_BITS", pixel_bus_width)

	return soc


def set_args(parser):
    #builder_args(parser)
    #soc_core_args(parser)
    parser.add_argument("--sdram-data-width",     default=128,             help="Set SDRAM chip data width.")
    parser.add_argument("--pixel-bus-width",      default=32,              help="Pixel access bus width")
    parser.add_argument("--sdram-init",           default=None,            help="SDRAM init file (.bin or .json).")

def main():
	from litex.build.parser import LiteXArgumentParser
	parser = LiteXArgumentParser(platform=digilent_arty.Platform, description="LiteX SoC on Arty A7")
	set_args(parser)
	args = parser.parse_args()
	soc = build_arty(args,
	  pixel_bus_width = int(args.pixel_bus_width),
	  no_compile_gateware = args.no_compile_gateware)


	builder = Builder(soc)
	builder.build(run=not args.no_compile_gateware)

if __name__ == "__main__":
	main()



