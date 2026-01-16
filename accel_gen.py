#!/usr/bin/env python3

# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only
#

from accelglue import AccelGlueSoC, AccelGluePlatform

from litex.soc.integration.builder import *
from litex.soc.integration.soc_core import *



# Build --------------------------------------------------------------------------------------------
def main():
    # Arguments.
    from litex.soc.integration.soc import LiteXSoCArgumentParser
    parser = LiteXSoCArgumentParser(description="Accel SoC generator")
    target_group = parser.add_argument_group(title="Generator options")
    target_group.add_argument("--name",          default="litex_soc", help="Accel SoC Name.")
    target_group.add_argument("--license-file",  default="LICENSE", help="License file to append")
    target_group.add_argument("--build",         action="store_true", help="Build SoC.")
    target_group.add_argument("--sys-clk-freq",  default=int(100e6),  help="System clock frequency.")

    #FIXME: receive CSR base as parameter, assumes 0

    builder_args(parser)
    soc_core_args(parser)
    args = parser.parse_args()

    # SoC.
    platform = AccelGluePlatform(args)
    platform.name = args.name
    busmaster_type = "native" #tested write ok
    #busmaster_type = "wishbone" #tested read-write ok
    soc = AccelGlueSoC(
        platform, busmaster_type, name = args.name, sys_clk_freq = int(float(args.sys_clk_freq)),
        **soc_core_argdict(args)
    )

    from wpu import WPUBase #FIXME: should be parametrized
    extcore = WPUBase(args.name, pixel_bus_width = 32)
    soc.add_core(extcore)

    # Build.
    builder = Builder(soc, **builder_argdict(args))
    builder.build(build_name=args.name, run=args.build)

if __name__ == "__main__":
    main()
