# Copyright (c) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

# Model of a 15.6" IPS FHD display
from pyopenscad import *

# Parameters
outline_w = 350.66
outline_h = 205.78
thickness = 3.2

polarizer_w = 347.16
polarizer_h = 196.59

active_w = 344.16
active_h = 193.59

pcba_t = thickness + 0.4
pcba_w = 281.5
pcba_h = 216.5 - outline_h #- pcba_t / 2.0
pcba_offset = 9.0

fpc_conn_w = 40 * 0.5 #40 pin connector 0.5" pitch
fpc_conn_h = 2.5

pin1_offset = 5.0
connector_w = fpc_conn_w + pin1_offset*2
connector_h = 12.0
connector_offset_h = 110.16 - pin1_offset
connector_offset_v = -thickness

# Colors
outline_color	= color([0.8, 0.8, 0.85])
polarizer_color	= color([0.1, 0.1, 0.1])
active_color	= color([0.25, 0.25, 0.25])
pcba_color		= color([0.3, 0.3, 0.35])
tape_color		= color([1.0, 0.3, 0.1])
connector_color	= color([0.25, 0.55, 0.3])
backlight_color = color([1.0, 1.0, 1.0])
fpc_conn_color	= color([.9,.8,0.35])

def make_front():
    outline = cube(size=[outline_w, outline_h, thickness], center=True)
    outline = outline_color.add(outline).comment("Outline")

    # Backlight zone
    backlight = rounded_rect(outline_w - 30.0*2, outline_h - 30.0*2, 16.3, .5)
    backlight = translate(v=[0, 0, -thickness / 2.0]).add(backlight)
    backlight = backlight_color.add(backlight).comment("Backlight")

    outline -= backlight

    # Polarizer layer
    polarizer = cube(size=[polarizer_w, polarizer_h, 0.3], center=True)
    polarizer = translate(v=[0, 0, thickness / 2.0 + 0.15]).add(polarizer)
    polarizer = polarizer_color.add(polarizer).comment("Polarizer")

    # Active Area
    active_area = cube(size=[active_w, active_h, 0.2], center=True)
    active_area = translate(v=[0, 0, thickness / 2.0 + 0.4]).add(active_area)
    active_area = active_color.add(active_area).comment("Active_area")

    # Pull tape on the right
    tape = cube(size=[8.0, 10.0, 0.2], center=False)
    tape = translate(v=[active_w / 2.0, (active_h) / 2.0 - 10.0, thickness / 2.0 + 0.25]).add(tape)
    tape = tape_color.add(tape).comment("Protective tape")

    # Bottom PCBA extension
    pcba = cube(size=[pcba_w, pcba_h + pcba_offset, pcba_t], center=True)
    pcba = translate(v=[0, -outline_h / 2.0 - (pcba_h-pcba_offset)/ 2.0, 0]).add(pcba)
    edge_cyl = cylinder(r=pcba_t/2, h=pcba_w, center=True, segments=32)
    edge_cyl =rotate(a=90, v=[0, 1, 0]).add(edge_cyl)
    edge_cyl = translate(v=[0, -outline_h / 2.0-pcba_h, 0]).add(edge_cyl)
    pcba = union().add(pcba).add(edge_cyl)
    pcba = pcba_color.add(pcba).comment("PCB Assembly")

    # Bottom connector aperture
    conn = cube(size=[connector_w, connector_h, 1], center=False)
    conn = translate(v=[-outline_w/2 + connector_offset_h,
                        -outline_h / 2.0 - pcba_h + connector_offset_v,
                        -thickness / 2.0 - 0.5]).add(conn)
    conn = connector_color.add(conn).comment("Connector")

    pcba -= conn

    # FPC connector inside connector
    fpc_conn = cube(size=[fpc_conn_w, fpc_conn_h, 0.5], center=True)
    fpc_conn = translate(v=[-outline_w/2 + connector_offset_h + connector_w/2,
                        -outline_h / 2.0 - pcba_h/2 + connector_offset_v,
                        -thickness / 2.0]).add(fpc_conn)
    fpc_conn = fpc_conn_color.add(fpc_conn).comment("FPC Connector")

    return [outline, polarizer, active_area, pcba, fpc_conn, tape]


def make_panel():
    panel = union()
    for part in make_front():
        panel.add(part)
    return panel.comment("Panel")

if __name__ == "__main__":
    model = make_panel()
    scad_render_to_file(model, "display_model.scad")

    
