# Copyright (c) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

from models import *

if __name__ == "__main__":
    import sys
    model = make_panel()
    scad_render_to_file(model, sys.argv[1])

    
