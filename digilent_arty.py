# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

# code portions from LiteX framework (C) Enjoy-Digital https://github.com/enjoy-digital/litex

import sys
import argparse

from accel_glue import gen_accel_cores

from migen import *
from litex.soc.cores.clock import *
from litex.soc.cores.video import VideoTimingGenerator, video_data_layout, video_timings
from litex.soc.interconnect import stream, wishbone
from litex.soc.interconnect.csr import AutoCSR, CSRStorage, CSRStatus
from litex.soc.integration.builder import *
from litex.soc.integration.soc_core import *
from litex.build.generic_platform import *

from litex_boards.platforms import digilent_arty

DVI = True

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
    def __init__(self, platform, sys_clk_freq, video_clock, with_dram, with_rst=True):
        self.rst = Signal()
        self.clock_domains.cd_sys = ClockDomain()

        self.submodules.pll = pll = S7PLL(speedgrade=-1)
        rst    = ~platform.request("cpu_reset") if with_rst else 0
        self.comb += pll.reset.eq(rst | self.rst)
        pll.register_clkin(platform.request("clk100"), 100e6)
        pll.create_clkout(self.cd_sys, sys_clk_freq)

        if DVI:
          self.clock_domains.cd_dvi   = ClockDomain()
          pll.create_clkout(self.cd_dvi,     video_clock)
          self.clock_domains.cd_dvi5x = ClockDomain()
          pll.create_clkout(self.cd_dvi5x, 5*video_clock)
        else:
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



timings1366x768 = ("1366x768@50Hz", {
        "pix_clk"       : 57.14e6,
        "h_active"      : 1366,
        "h_blanking"    : 32+(32+5)+34, #front, sync, back
        "h_sync_offset" : 32,
        "h_sync_width"  : 32+5,
        "v_active"      : 768,
        "v_blanking"    : 2+(2+2)+4, #front, sync, back
        "v_sync_offset" : 2,
        "v_sync_width"  : 2+2,
})

def build_arty(args, pixel_bus_width=32, with_video_framebuffer=True, no_compile_gateware=False):
	timings_sel = timings1366x768
	timings = timings_sel[1]
	timings["pix_clk"] = 60e6 #adjust to allow a possible PLL configuration
	
	#supported toolchains: "yosys+nextpnr" or "vivado"
	platform = digilent_arty.Platform(variant="a7-35", toolchain=args.toolchain)

	sys_clk_freq = int(100e6)
	soc = SoCCore(platform, sys_clk_freq, **soc_core_argdict(args))
	#use with_rst=False for mpremote (or when serial connection has to avoid reset)
	soc.submodules.crg = _CRG(platform, sys_clk_freq, timings["pix_clk"], True, with_rst=False)

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
	if with_video_framebuffer and DVI:
	    dvi_pins  = "01234567" # "62514073" for machdyne dadapter (for TMDS_33, odd-even should be next to each other: "01234567")
	    pmod_dvi  = "pmodc" #must be port C for TDMS_33, ports A-D on Arty has 200 ohm series protection resistors
	    dvi_iostd = "TMDS_33"
	    platform.add_extension([("dvi_out", 0, #DVI pmod breakout on pmod C (seems not working in others than C)
                Subsignal("data0_p", Pins(f"{pmod_dvi}:{dvi_pins[0]}"), IOStandard(dvi_iostd)), #B0+
                Subsignal("data0_n", Pins(f"{pmod_dvi}:{dvi_pins[1]}"), IOStandard(dvi_iostd)), #B0-
                Subsignal("data1_p", Pins(f"{pmod_dvi}:{dvi_pins[2]}"), IOStandard(dvi_iostd)), #G1+
                Subsignal("data1_n", Pins(f"{pmod_dvi}:{dvi_pins[3]}"), IOStandard(dvi_iostd)), #G1-
                Subsignal("data2_p", Pins(f"{pmod_dvi}:{dvi_pins[4]}"), IOStandard(dvi_iostd)), #R2+
                Subsignal("data2_n", Pins(f"{pmod_dvi}:{dvi_pins[5]}"), IOStandard(dvi_iostd)), #R2-
                Subsignal("clk_p",   Pins(f"{pmod_dvi}:{dvi_pins[6]}"), IOStandard(dvi_iostd)),
                Subsignal("clk_n",   Pins(f"{pmod_dvi}:{dvi_pins[7]}"), IOStandard(dvi_iostd)))
                ])
	    video_clock_domain = "dvi"
	    from litex.soc.cores.video import VideoS7HDMIPHY
	    soc.submodules.videophy = VideoS7HDMIPHY(platform.request("dvi_out"), clock_domain=video_clock_domain)
	elif with_video_framebuffer:
		platform.add_extension([("vga", 0, #PMOD VGA on pmod B & C
			Subsignal("hsync", Pins("U14")), #pmodc.4
			Subsignal("vsync", Pins("V14")), #pmodc.5
			Subsignal("r", Pins("E15 E16 D15 C15")), #pmodb.0-3
			Subsignal("g", Pins("U12 V12 V10 V11")), #pmodc.0-3
			Subsignal("b", Pins("J17 J18 K15 J15")), #pmodb.4-7
			IOStandard("LVCMOS33"))])
			
		video_clock_domain = "vga"
		soc.submodules.videophy = VideoGenericPHY_SDR(platform.request("vga"), clock_domain=video_clock_domain)
	
	if with_video_framebuffer:
		soc.add_video_framebuffer(phy=soc.videophy, timings=timings_sel, clock_domain=video_clock_domain, format="rgb888")

		corelist = ["rectangle_fill32", "ellipse_fill32", "line32"]
		gen_accel_cores(soc, corelist, pixel_bus_width)

		soc.add_constant("SDRAM_BUS_BITS", pixel_bus_width)

	# SD card -------------------------------------------------------------------------------------
	with_sdcard = False
	if with_sdcard:
		ext = digilent_arty.sdcard_pmod_io("pmoda")
		soc.platform.add_extension(ext)
		soc.add_sdcard()
	
	#Hardware JPEG decoder
	with_jpeg_decoder = True
	if with_jpeg_decoder:
		from videocodecs import JPEGDecoder
		rdport = soc.sdram.crossbar.get_port(mode="read", data_width=32)
		wrport = soc.sdram.crossbar.get_port(mode="write", data_width=32)
		soc.submodules.jpeg_decoder = JPEGDecoder(rdport=rdport, wrport=wrport) #add JPEG decoder
		soc.platform.add_source_dir("core_jpeg/src_v") #for jpeg_core.v and dependencies

	if True:
		soc.add_constant("UART_POLLING") #FIXME: this is currently needed to be able to read from UART

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



