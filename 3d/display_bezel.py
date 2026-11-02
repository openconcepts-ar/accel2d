# Copyright (c) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

# Model of a display bezel
from pyopenscad import *

# Parameters

pcba_h = 12
display_w = 350.66 + .5
display_h = 205.78 + .5
active_w = display_w - (350.66-344.16)+1
active_h = display_h - (205.78-193.59)+1
display_h += pcba_h
front_thichness = 1
bezel_border_w = 35
bezel_border_h = 25
bezel_corner_radius = 15

bezel_thickness = 7
display_thickness = 3.4
outline_color = color([.5, .5, .5])
aperture_color = color([.4, .4, .4])

def make_bezel():
    outline = rounded_rect(display_w+bezel_border_w, display_h+bezel_border_h, bezel_corner_radius, thickness = bezel_thickness)
    outline = translate(v=[0, -pcba_h/2, -bezel_thickness / 2.0]).add(outline)
    outline = outline_color.add(outline).comment("Bezel")
    
    display_aperture = cube(size=[display_w, display_h, bezel_thickness], center=True)
    display_aperture = translate(v=[0, -pcba_h/2, -bezel_thickness/2+-front_thichness]).add(display_aperture)
    display_aperture += cube(size=[active_w, active_h, front_thichness*2.1], center=True)
    display_aperture += translate(v=[-display_w/2+120, -(display_h+pcba_h)/2, -bezel_thickness]).add(cube(size=[50, pcba_h, bezel_thickness], center=True))
    display_aperture = aperture_color.add(display_aperture)
    
    outline -= display_aperture
    return outline
    

if __name__ == "__main__":
    model = make_bezel()
    if False: #show placed display
    	import display_model
    	display = display_model.make_panel()
    	display = translate(v=[0, 0, -display_model.thickness/2-front_thichness]).add(display)
    	model = union().add(display).add(model)
    scad_render_to_file(model, "display_bezel.scad")

    

