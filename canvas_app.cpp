// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only
// tree drawing based on https://github.com/SagarGaniga
// Copyright (c) 2017 Sagar Ganiga MIT License 

#include "misc.h"
#include "processing_api.h"

using namespace processing;
PGraphics canvas;
PFont dejavu;

#include "DejaVuSansMono.ttf.c" //inline font data

void setup()
{
    dejavu = createFont("DejaVuSansMono.ttf", 25, DejaVuSansMono_ttf, DejaVuSansMono_ttf_len);
    canvas.background(BLACK);
    canvas.clear();
    canvas.background(0x08, 0x29, 0x5f);

    srand(0); //fixed random seed
    println("drawing start");
}

//line based fractal
void tree(float x, float y, float length, float arg)
{
	if(length < 5) return;
	float dx = length*sin(arg), dy = length*cos(arg);
    for(int i = 0; i < length/8; ++i)
    {
	    float k = random(-.2, .2);
	    int x0 = x + dy*k, y0 = y - dx*k;

	    canvas.line(x0, y0, x0+dx, y0-dy);
	}

	//recurse two branches
    tree(x+dx, y-dy, length*random(.7, .9), arg+random(.6));
    tree(x+dx, y-dy, length*random(.7, .9), arg-random(.5));
}

void draw()
{
    //blue sky as rounded rect
    canvas.fill(canvas.background());
    canvas.rect(200, 100, canvas.width-200, canvas.height-100, 20);
    
    //point based stars
    canvas.stroke(WHITE);
    for(int i = 0; i < 30; ++i)
      canvas.point(random(210, canvas.width-210),  random(110, canvas.height/2));

    //cirles based moon
    canvas.fill(WHITE);
    canvas.ellipse(canvas.width-300, 175, 20, 20);
    canvas.fill(canvas.background());
    canvas.lastshape(-10, -5);

    //picture title
    canvas.fill(DARKGRAY);
	canvas.textFont(dejavu);
    canvas.text("m o o n l i g h t", 220, canvas.height-50);

    //draw fractal
    canvas.stroke(BLACK);
    tree(canvas.width*.4, canvas.height-100, canvas.height/8, 0);
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

