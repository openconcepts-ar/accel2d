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

OPENLDI = True
VIDEO_TERMINAL = False

from litex.build.io import SDROutput, DDROutput
from litex.soc.cores.code_tmds import TMDSEncoder
from litex.soc.cores.video import VideoTimingGenerator, VideoFrameBuffer, video_timing_layout, _dvi_c2d, video_data_layout

from openldi import VideoOPENLDIPHY

lvds1366x768rb50_timings = ("1366x768@50Hz", {
        "pix_clk"       : 60e6,
        "h_active"      : 1366,
        "h_blanking"    : 48+32+54,  #front, sync, back (total 1500)
        "h_sync_offset" : 48,
        "h_sync_width"  : 32,
        "v_active"      : 768,       #total 800
        "v_blanking"    : 3+5+24,    #front, sync, back
        "v_sync_offset" : 3,
        "v_sync_width"  : 5,
})

# CRG ----------------------------------------------------------------------------------------------

class _CRGSDRAM(LiteXModule):
    def __init__(self, platform, sys_clk_freq, video_clock, with_usb_pll=False):
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
        self.submodules += vga_pll
        self.comb += vga_pll.reset.eq(~por_done)
        vga_pll.register_clkin(clk48, 48e6)
        if OPENLDI:
            self.cd_openldi   = ClockDomain()
            self.cd_openldi3p5x = ClockDomain()
            vga_pll.create_clkout(self.cd_openldi,        video_clock, margin=1e-3)
            vga_pll.create_clkout(self.cd_openldi3p5x, 3.5*video_clock, margin=1e-3)
        

        # FPGA Reset (press usr_btn for 1 second to fallback to bootloader)
        reset_timer = WaitTimer(int(48e6))
        reset_timer = ClockDomainsRenamer("por")(reset_timer)
        self.submodules += reset_timer
        self.comb += reset_timer.wait.eq(~rst_n)
        self.comb += platform.request("rst_n").eq(~reset_timer.done)

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, revision="0.1", device="25F", sdram_device="MT41K64M16",
                 sys_clk_freq=int(96e6), toolchain="trellis", with_led_chaser=False, with_gpio=False, **kwargs):
        platform = gsd_orangecrab.Platform(revision=revision, device=device ,toolchain=toolchain)

        # CRG --------------------------------------------------------------------------------------
        crg_cls      = _CRGSDRAM if kwargs.get("integrated_main_ram_size", 0) == 0 else _CRG
        
        if OPENLDI:
            timings = lvds1366x768rb50_timings #this allows console at 50Hz/60Hz with 75Mhz sys clock (45F part speed -6), and framebuffer at 50Hz with 96Mhz(or 90-100?Mhz) clock
            timings[1]["pix_clk"] *= 30.0/50.0 #this alters display refresh (75mhz sys works up to 30 Hz if using DRAM framebuffer at rgb888, 30/60hz possible with console or rgb555)
            totalpix = (timings[1]["h_active"]+timings[1]["h_blanking"])*(timings[1]["v_active"]+timings[1]["v_blanking"])
            print(timings, "refresh", timings[1]["pix_clk"]/totalpix)
            #quit()
        self.crg = crg_cls(platform, sys_clk_freq, timings[1]["pix_clk"], with_usb_pll=True)

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

        with_north_uart = True
        if with_north_uart:
            platform.add_extension([("uart2", 0,
              Subsignal("tx", Pins("N16")), #IO_MOSI/nRTS
              Subsignal("rx", Pins("N15")), #IO_MISO/nCTS
              IOStandard("LVCMOS33")
            )])
            #def add_uart(self, name="uart", uart_name="serial", uart_pads=None, baudrate=115200, fifo_depth=16, with_dynamic_baudrate=False, rx_fifo_rx_we=False):
            pads = platform.request("uart2")
            baudrate = 115200
            #TODO: fifo can be smaller if using interrupts
            self.add_uart(name="uart2", uart_name="uart2", uart_pads=pads,
            	baudrate=baudrate, fifo_depth=128, with_dynamic_baudrate=True, rx_fifo_rx_we=True)
            self.add_constant("LITEX_UART2_DEFAULT_BAURDATE", baudrate);
        
        # GPIO -------------------------------------------------------------------------------------
        if with_gpio:
            # (FIXME: south TP_INT is NC in FPGA board)
            gpiopads = "C9 C10 H4 G4" #north SCL=C9, SDA=C10 south SCL2=H4, SDA2=G4
            ext = [("gpio", 0, Pins(gpiopads), IOStandard("LVCMOS33"))] #first 8 bits are dummy since required by software-only USB host
            platform.add_extension(ext)
            self.submodules.gpio = GPIOTristate(platform.request("gpio"))

        with_video_framebuffer = True
        if with_video_framebuffer and OPENLDI:
        	platform.add_extension([("openldi_out", 0, #can use GND and just 4 more wires
                #TOP TO BOTTOM
                Subsignal("clk", Pins("N4"), IOStandard("LVCMOS33D"), Misc("SLEWRATE=FAST"), Misc("DRIVE=4")), #aux0-=N3, aux0+=N4 INVERT
                Subsignal("tx2", Pins("H3"), IOStandard("LVCMOS33D"), Misc("SLEWRATE=FAST"), Misc("DRIVE=4")), #aux1-=G3, aux1+=H3 INVERT
                Subsignal("tx1", Pins("F2"), IOStandard("LVCMOS33D"), Misc("SLEWRATE=FAST"), Misc("DRIVE=4")), #aux2-=G1, aux2+=F2 INVERT
                Subsignal("tx0", Pins("F4"), IOStandard("LVCMOS33D"), Misc("SLEWRATE=FAST"), Misc("DRIVE=4")), #aux6+=F4, aux6-=F3
                )])
        	openldi_domain = "openldi"
        	self.submodules.videophy = VideoOPENLDIPHY(platform.request("openldi_out"), clock_domain=openldi_domain, clock_domain3p5x="openldi3p5x", pn_swap="12c")
        	if VIDEO_TERMINAL:
        	    self.add_video_terminal(phy=self.videophy, timings=timings, clock_domain=openldi_domain)
        	else:
        	    #pixel_format = "rgb888"
        	    pixel_format = "rgb565"
        	    fifo_depth = timings[1]["h_active"] + timings[1]["h_blanking"] #one line
        	    #FIFO size configuration was upstreamed at my request https://github.com/enjoy-digital/litex/issues/1931
        	    self.add_video_framebuffer(phy=self.videophy, timings=timings, clock_domain=openldi_domain, format=pixel_format, fifo_depth=fifo_depth*5) #needs more than one line at 75Mhz sys and 30/50Hz refresh

        	platform.add_extension([("backlight", 0,
                Subsignal("en", Pins("A10"), IOStandard("LVCMOS33")), #A10=SPI_0
                Subsignal("pwm", Pins("C11"), IOStandard("LVCMOS33")) #C11=SPI_1
                )])
        	bl = platform.request("backlight")
        	self.comb += [bl.en.eq(1), bl.pwm.eq(1)] #always enable backlight


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
    parser.add_target_argument("--with-gpio",      action="store_true",              help="Enable GPIOs") #FIXME: hardware I2C is better

def main():
    from litex.build.parser import LiteXArgumentParser
    parser = LiteXArgumentParser(platform=gsd_orangecrab.Platform, description="LiteX SoC on OrangeCrab")
    parser.add_target_argument("--device",          default="45F",       help="ECP5 device")
    parser.add_target_argument("--sys-clk-freq",    default=75e6,        help="System clock frequency.") #framebuffer works down to 75MHz with 1366x768@30Hz, for 50Hz see above
    set_args(parser)

    args = parser.parse_args()

    soc = BaseSoC(
        device                 = args.device,
        sys_clk_freq           = int(float(args.sys_clk_freq)),
        toolchain              = args.toolchain,
        pixel_bus_width = int(args.pixel_bus_width),
        with_gpio = args.with_gpio,
        **parser.soc_argdict
    )
    
    
    add_accel_cores(soc)
    
    builder = Builder(soc, **parser.builder_argdict)
    builder.build(**parser.toolchain_argdict, run=not args.no_compile_gateware)

if __name__ == "__main__":
    main()

