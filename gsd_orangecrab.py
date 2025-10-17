#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) Greg Davill <greg.davill@gmail.com>
# Copyright (c) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

import os
import sys

from migen import *
from migen.genlib.misc import WaitTimer
from migen.genlib.resetsync import AsyncResetSynchronizer

from accel_glue import gen_accel_cores
from litex.gen import LiteXModule

from litex_boards.platforms import gsd_orangecrab

from litex.soc.cores.clock import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser
from litex.soc.cores.gpio import GPIOTristate #required for USB host

from litedram.modules import MT41K64M16, MT41K128M16, MT41K256M16, MT41K512M16
from litedram.phy import ECP5DDRPHY

from litex.build.generic_platform import Pins, IOStandard, Subsignal, Drive, Misc
from litex.soc.interconnect.csr import AutoCSR, CSRStorage
from litex.soc.interconnect import stream, wishbone
from litex.soc.interconnect.csr import CSRStatus

DVI = True

# CRG ----------------------------------------------------------------------------------------------

class _CRGSDRAM(LiteXModule):
    def __init__(self, platform, sys_clk_freq, with_usb_pll=False):
        self.rst = Signal()
        self.cd_init     = ClockDomain()
        self.cd_por      = ClockDomain()
        self.cd_sys      = ClockDomain()
        self.cd_sys2x    = ClockDomain()
        self.cd_sys2x_i  = ClockDomain()

        # # #

        self.stop  = Signal()
        self.reset = Signal()

        # Clk / Rst
        clk48 = platform.request("clk48")
        rst_n = platform.request("usr_btn", loose=True)
        if rst_n is None: rst_n = 1

        # Power on reset
        por_count = Signal(16, reset=2**16-1)
        por_done  = Signal()
        self.comb += self.cd_por.clk.eq(clk48)
        self.comb += por_done.eq(por_count == 0)
        self.sync.por += If(~por_done, por_count.eq(por_count - 1))

        # PLL
        sys2x_clk_ecsout = Signal()
        self.pll = pll = ECP5PLL()
        self.comb += pll.reset.eq(~por_done | ~rst_n | self.rst)
        pll.register_clkin(clk48, 48e6)
        pll.create_clkout(self.cd_sys2x_i, 2*sys_clk_freq)
        pll.create_clkout(self.cd_init, 24e6)
        self.specials += [
            Instance("ECLKBRIDGECS",
                i_CLK0   = self.cd_sys2x_i.clk,
                i_SEL    = 0,
                o_ECSOUT = sys2x_clk_ecsout),
            Instance("ECLKSYNCB",
                i_ECLKI = sys2x_clk_ecsout,
                i_STOP  = self.stop,
                o_ECLKO = self.cd_sys2x.clk),
            Instance("CLKDIVF",
                p_DIV     = "2.0",
                i_ALIGNWD = 0,
                i_CLKI    = self.cd_sys2x.clk,
                i_RST     = self.reset,
                o_CDIVX   = self.cd_sys.clk),
            AsyncResetSynchronizer(self.cd_sys, ~pll.locked | self.reset),
        ]

        # USB PLL
        if with_usb_pll:
            self.cd_usb_12 = ClockDomain()
            self.cd_usb_48 = ClockDomain()
            usb_pll = ECP5PLL()
            self.submodules += usb_pll
            self.comb += usb_pll.reset.eq(~por_done)
            usb_pll.register_clkin(clk48, 48e6)
            usb_pll.create_clkout(self.cd_usb_48, 48e6)
            usb_pll.create_clkout(self.cd_usb_12, 12e6)
            
            
        # Video PLL
        vga_pll = ECP5PLL()
        #video_clock = 25e6 #25e6 for 640x480
        video_clock = 40e6 #40e6 for 800x600
        self.submodules += vga_pll
        self.comb += vga_pll.reset.eq(~por_done)
        vga_pll.register_clkin(clk48, 48e6)
        if DVI:
            self.cd_hdmi   = ClockDomain()
            self.cd_hdmi5x = ClockDomain()
            vga_pll.create_clkout(self.cd_hdmi,     video_clock, margin=1e-2)
            vga_pll.create_clkout(self.cd_hdmi5x, 5*video_clock, margin=1e-2) #ECP5 max: 400MHz
        else: 
            self.cd_vga  = ClockDomain()
            vga_pll.create_clkout(self.cd_vga, video_clock)
        

        # FPGA Reset (press usr_btn for 1 second to fallback to bootloader)
        reset_timer = WaitTimer(int(48e6))
        reset_timer = ClockDomainsRenamer("por")(reset_timer)
        self.submodules += reset_timer
        self.comb += reset_timer.wait.eq(~rst_n)
        self.comb += platform.request("rst_n").eq(~reset_timer.done)

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, revision="0.1", device="25F", sdram_device="MT41K64M16",
                 sys_clk_freq=int(48e6), toolchain="trellis", with_led_chaser=False, **kwargs):
        platform = gsd_orangecrab.Platform(revision=revision, device=device ,toolchain=toolchain)

        # CRG --------------------------------------------------------------------------------------
        crg_cls      = _CRGSDRAM if kwargs.get("integrated_main_ram_size", 0) == 0 else _CRG
        self.crg = crg_cls(platform, sys_clk_freq, with_usb_pll=True)

        # SoCCore ----------------------------------------------------------------------------------
        # Defaults to USB ACM through ValentyUSB.
        #kwargs["uart_name"] = "usb_acm" #set this to get USB ACM serial, or use --uart-name=usb_acm 
        platform.add_extension(gsd_orangecrab.feather_serial) #rx=GPIO:0 & tx=GPIO:1
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on OrangeCrab", **kwargs)

        # DDR3 SDRAM -------------------------------------------------------------------------------
        if not self.integrated_main_ram_size:
            available_sdram_modules = {
                "MT41K64M16":  MT41K64M16,
                "MT41K128M16": MT41K128M16,
                "MT41K256M16": MT41K256M16,
                "MT41K512M16": MT41K512M16,
            }
            sdram_module = available_sdram_modules.get(sdram_device)

            ddram_pads = platform.request("ddram")
            self.ddrphy = ECP5DDRPHY(
                pads         = ddram_pads,
                sys_clk_freq = sys_clk_freq,
                dm_remapping = {0:1, 1:0},
                cmd_delay    = 0 if sys_clk_freq > 64e6 else 100)
            self.ddrphy.settings.rtt_nom = "disabled"
            if hasattr(ddram_pads, "vccio"):
                self.comb += ddram_pads.vccio.eq(0b111111)
            if hasattr(ddram_pads, "gnd"):
                self.comb += ddram_pads.gnd.eq(0)
            self.comb += self.crg.stop.eq(self.ddrphy.init.stop)
            self.comb += self.crg.reset.eq(self.ddrphy.init.reset)
            self.add_sdram("sdram",
                phy           = self.ddrphy,
                module        = sdram_module(sys_clk_freq, "1:2"),
                l2_cache_size = kwargs.get("l2_size", 8192)
            )

        # Leds -------------------------------------------------------------------------------------
        if with_led_chaser:
            self.leds = LedChaser(
                pads         = platform.request_all("user_led"),
                sys_clk_freq = sys_clk_freq)

        # GPIO -------------------------------------------------------------------------------------
        with_pmod_gpio = True #GPIO required for USB host, still allows 4 channels of differential outputs on SOUTH connector (i.e. DVI)
        if with_pmod_gpio:
            pa = ["F1", "H1", "A8", "H2", "C8", "B8", "B10", "B9"] #bits 0-7 on NORTH connector (outer side): AUX_3+/AUX_3-/IO_11/IO_12/IO_9/IO_10/IO_5/IO_6
            pd = ["R17", "J2", "C10", "C9", "A10", "C11", "A11", "B11"] #USB device on USB and others: IO_SCK/IO_13/IO_SDA/IO_SCL/SPI_0/SPI_1/USBH_D+/USBH_D- (bits 8-16)
            ext = [("gpio", 0, Pins(" ".join(pa + pd)), IOStandard("LVCMOS33"))] #first 8 bits are dummy since required by software-only USB host
            platform.add_extension(ext)
            self.submodules.gpio = GPIOTristate(platform.request("gpio"))
            self.add_constant("LITEX_SOFTUSB_HOST");


        with_video_framebuffer = True
        if with_video_framebuffer and DVI:
        	from litex.soc.cores.video import VideoHDMIPHY
        	platform.add_extension([("hdmi_out", 0, #can use GND and just 4 more wires
                #TOP TO BOTTOM
                Subsignal("data2_p", Pins("N4"), IOStandard("LVCMOS33D"), Misc("DRIVE=8"), Misc("SLEWRATE=FAST")), #aux0-=N3, aux0+=N4 INVERT
                Subsignal("data1_p", Pins("H3"), IOStandard("LVCMOS33D"), Misc("DRIVE=8"), Misc("SLEWRATE=FAST")), #aux1-=G3, aux1+=H3 INVERT
                Subsignal("data0_p", Pins("F2"), IOStandard("LVCMOS33D"), Misc("DRIVE=8"), Misc("SLEWRATE=FAST")), #aux2-=G1, aux2+=F2 INVERT
                Subsignal("clk_p",   Pins("F4"), IOStandard("LVCMOS33D"), Misc("DRIVE=8"), Misc("SLEWRATE=FAST")), #aux6+=F4, aux6-=F3
                )])
        	self.submodules.videophy = VideoHDMIPHY(platform.request("hdmi_out"), clock_domain="hdmi", pn_swap="rgb")
        	#self.add_video_framebuffer2(phy=self.videophy, timings="640x480@60Hz", clock_domain="hdmi", format="rgb888")
        	self.add_video_framebuffer2(phy=self.videophy, timings="800x600@60Hz", clock_domain="hdmi", format="rgb888")
        	
        elif with_video_framebuffer:
            platform.add_extension([("vga", 0,
                Subsignal("hsync", Pins("A10")), #SPI_0
                Subsignal("vsync", Pins("J3")), #LED_B #- pol for 1024x768, but + works
                Subsignal("b", Pins("H3")), #aux1+
                Subsignal("g", Pins("B9")), #IO_6
                Subsignal("r", Pins("N4")), #aux0+
                IOStandard("LVCMOS33"))])
            from litex.soc.cores.video import VideoVGAPHY
            self.submodules.videophy = VideoVGAPHY(platform.request("vga"), clock_domain="vga")
            self.add_video_framebuffer2(phy=self.videophy, timings="640x480@60Hz", clock_domain="vga", format="rgb888")

    #NOTE: this is the same as the base implementation but allows to specify the fifo depth
    #it's needed to synth in the 25F
    def add_video_framebuffer2(self, name="video_framebuffer", phy=None, timings="800x600@60Hz", clock_domain="sys", format="rgb888", fifo_depth=16384):
        # Imports.
        from litex.soc.cores.video import VideoTimingGenerator, VideoFrameBuffer

        # Video Timing Generator.
        vtg = VideoTimingGenerator(default_video_timings=timings if isinstance(timings, str) else timings[1])
        vtg = ClockDomainsRenamer(clock_domain)(vtg)
        self.add_module(name=f"{name}_vtg", module=vtg)

        # Video FrameBuffer.
        timings = timings if isinstance(timings, str) else timings[0]
        base = self.mem_map.get(name, None)
        from litex.soc.integration.soc import SoCRegion
        if base is None:
            self.bus.add_region(name, SoCRegion(
                origin = 0x40c00000,
                size   = 0x800000,
                linker = True)
            )
            base = self.bus.regions[name].origin
        hres = int(timings.split("@")[0].split("x")[0])
        vres = int(timings.split("@")[0].split("x")[1])
        vfb = VideoFrameBuffer(self.sdram.crossbar.get_port(),
            hres   = hres,
            vres   = vres,
            base   = base,
            format = format,
            clock_domain          = clock_domain,
            clock_faster_than_sys = vtg.video_timings["pix_clk"] >= self.sys_clk_freq,
            fifo_depth = fifo_depth
        )
        self.add_module(name=name, module=vfb)

        # Connect Video Timing Generator to Video FrameBuffer.
        self.comb += vtg.source.connect(vfb.vtg_sink)

        # Connect Video FrameBuffer to Video PHY.
        self.comb += vfb.source.connect(phy if isinstance(phy, stream.Endpoint) else phy.sink)

        # Constants.
        self.add_constant("VIDEO_FRAMEBUFFER_BASE", base)
        self.add_constant("VIDEO_FRAMEBUFFER_HRES", hres)
        self.add_constant("VIDEO_FRAMEBUFFER_VRES", vres)
        self.add_constant("VIDEO_FRAMEBUFFER_DEPTH", vfb.depth)

# LiteXSoCArgumentParser ---------------------------------------------------------------------------

from litex.build.parser import LiteXArgumentParser

class LiteXSoCArgumentParser(LiteXArgumentParser): pass # FIXME: Add compat and remove.
# Build --------------------------------------------------------------------------------------------

def add_accel_cores(soc, pixel_bus_width = 32):
    corelist = ["line32a"]
    #corelist = ["rectangle_fill32"]
    #corelist = ["rectangle_fill32", "ellipse_fill32", "line32"]
    #corelist = ["rectangle_fill32", "line32"]
    gen_accel_cores(soc, corelist, pixel_bus_width)
    soc.add_constant("SDRAM_BUS_BITS", pixel_bus_width)

def set_args(parser):
    parser.add_target_argument("--sdram-data-width",     default=128,             help="Set SDRAM chip data width.")
    parser.add_target_argument("--pixel-bus-width",      default=32,              help="Pixel access bus width")
    parser.add_target_argument("--sdram-init",           default=None,            help="SDRAM init file (.bin or .json).")

def main():
    from litex.build.parser import LiteXArgumentParser
    parser = LiteXArgumentParser(platform=gsd_orangecrab.Platform, description="LiteX SoC on OrangeCrab")
    parser.add_target_argument("--device",          default="25F",       help="ECP5 device")
    parser.add_target_argument("--sys-clk-freq",    default=50e6,        help="System clock frequency.")
    set_args(parser)

    args = parser.parse_args()

    soc = BaseSoC(
        device                 = args.device,
        sys_clk_freq           = int(float(args.sys_clk_freq)),
        toolchain              = args.toolchain,
        pixel_bus_width = int(args.pixel_bus_width),
        **parser.soc_argdict
    )
    
    
    add_accel_cores(soc)
    
    builder = Builder(soc, **parser.builder_argdict)
    builder.build(**parser.toolchain_argdict, run=not args.no_compile_gateware)

if __name__ == "__main__":
    main()
    

