// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "misc.h"
#include "processing_api.h"

using namespace processing;
PGraphics canvas;
PFont dejavu;

#include "DejaVuSansMono.ttf.c" //inline font data

void setup()
{
    dejavu = createFont("DejaVuSansMono.ttf", 75, DejaVuSansMono_ttf, DejaVuSansMono_ttf_len);
    canvas.clear();
    println("drawing start");
}

void draw()
{
    //oblique lines
    canvas.stroke(GRAY);
    for(int x = 0; x < canvas.width; x += 8) 
	    canvas.line(x, 0, x*2 - canvas.width, canvas.height);

    //rectangular shapes
    canvas.fill(BLUE);
    canvas.rect(400, 50, 600, 400);
    canvas.fill(GREEN);
    canvas.rect(10, 175, 300, 400, 15); //rounded corners

    //ellipse with shadow
    canvas.fill(BLACK);
    canvas.ellipse(320, 170, 100, 80);
    canvas.fill(WHITE);
    canvas.lastshape(-10, -10);

    //text
    canvas.fill(RED);
	canvas.textFont(dejavu);
    canvas.text("Hello", 30, 320);
}

extern "C" int graphics_app(void)
{
	setup();
	draw();
	return 0;
} 

//include all source dependencies
#include "accel_canvas.cpp"
#include "processing_api.cpp"

