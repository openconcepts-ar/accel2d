# Copyright (c) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
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
pcba_h = 216.5 - outline_h - pcba_t / 2.0
pcba_offset = 9.0

fpc_conn_w = 40 * 0.5 #40 pin connector 0.5" pitch
fpc_conn_h = 2.5

pin1_offset = 5.0
connector_w = fpc_conn_w + pin1_offset*2
connector_h = 10.0
connector_offset_h = 110.16 - pin1_offset
connector_offset_v = 0.5

# Colors
outline_color	= color([0.8, 0.8, 0.85])
polarizer_color	= color([0.1, 0.1, 0.1])
active_color	= color([0.25, 0.25, 0.25])
pcba_color		= color([0.3, 0.3, 0.35])
tape_color		= color([1.0, 0.3, 0.1])
connector_color	= color([0.25, 0.55, 0.3])
backlight_color = color([1.0, 1.0, 1.0])

def make_front():
    outline = cube(size=[outline_w, outline_h, thickness], center=True)
    outline = outline_color.add(outline)

    # Polarizer layer
    polarizer = cube(size=[polarizer_w, polarizer_h, 0.3], center=True)
    polarizer = translate(v=[0, 0, thickness / 2.0 + 0.15]).add(polarizer)
    polarizer = polarizer_color.add(polarizer)

    # Active Area
    active_area = cube(size=[active_w, active_h, 0.2], center=True)
    active_area = translate(v=[0, 0, thickness / 2.0 + 0.4]).add(active_area)
    active_area = active_color.add(active_area)

    # Pull tape on the right
    tape = cube(size=[8.0, 10.0, 0.2], center=False)
    tape = translate(v=[active_w / 2.0, (active_h) / 2.0 - 10.0, thickness / 2.0 + 0.25]).add(tape)
    tape = tape_color.add(tape)

    # Bottom PCBA extension
    pcba = cube(size=[pcba_w, pcba_h + pcba_offset, pcba_t], center=True)
    pcba = translate(v=[0, -outline_h / 2.0 - (pcba_h-pcba_offset)/ 2.0, 0]).add(pcba)
    edge_cyl = cylinder(r=pcba_t/2, h=pcba_w, center=True, segments=32)
    edge_cyl =rotate(a=90, v=[0, 1, 0]).add(edge_cyl)
    edge_cyl = translate(v=[0, -outline_h / 2.0-pcba_h, 0]).add(edge_cyl)
    pcba = union().add(pcba).add(edge_cyl)
    pcba = pcba_color.add(pcba)

    return [outline, polarizer, active_area, pcba, tape]

def rounded_rect(w, h, r, thickness=0.2, segments=32):
    u = union()

    # Main body
    u.add(cube(size=[w - 2 * r, h, thickness], center=True))
    u.add(cube(size=[w, h - 2 * r, thickness], center=True))

    # Corner cylinders
    for sx in (-1, 1):
        for sy in (-1, 1):
            c = cylinder(r=r, h=thickness, center=True, segments=segments)
            c = translate(v=[sx * (w / 2.0 - r),
                             sy * (h / 2.0 - r),
                             0]).add(c)
            u.add(c)

    return u


def make_back():
    # Bottom connector hole area
    conn = cube(size=[connector_w, connector_h, 0.5], center=False)
    conn = translate(v=[-outline_w/2 + connector_offset_h,
                        -outline_h / 2.0 - pcba_h + connector_offset_v,
                        -thickness / 2.0 - 0.5]).add(conn)
    conn = connector_color.add(conn)
    
    #FPC connector inside connector
    fpc_conn = cube(size=[fpc_conn_w, fpc_conn_h, 0.5], center=True)
    fpc_conn = translate(v=[-outline_w/2 + connector_offset_h + connector_w/2,
                        -outline_h / 2.0 - pcba_h/2 + connector_offset_v,
                        -thickness / 2.0 - 0.5]).add(fpc_conn)
    fpc_conn = color([.9,.8,0.35]).add(fpc_conn)

    # Backlight zone
    backlight = rounded_rect(outline_w - 30.0*2, outline_h - 30.0*2, 16.3)
    backlight = translate(v=[0, 0, -thickness / 2.0 - 0.15]).add(backlight)
    backlight = backlight_color.add(backlight)

    return [backlight, conn, fpc_conn]


def make_panel():
    panel = union()
    for part in make_front() + make_back():
        panel.add(part)
    return panel

if __name__ == "__main__":
    model = make_panel()
    scad_render_to_file(model, "display_model.scad")

    
