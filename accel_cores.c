// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>
#include <stdlib.h> //abs

#include "misc.h" //just for ACCEL_STATIC_ASSERT
#include "accel_cores.h"
#include "graphics.h"
#include "sw_cores.h"

//#define INDUCE_RENDERING_ERRORS //enable to induce errors in softwre renderer

unsigned accel_rectangle_fill(accel_rectangle_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_rectangle_fill32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_RECTANGLE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_RECTANGLE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stps
    while(regs->done); //wait data latch
  }


  fb_base += (y0<y1?y0:y1)*FRAME_PITCH + (x0<x1?x0:x1)*sizeof(rgba);
  regs->x0 = x0 < x1 ? x0 : x1;
  regs->x1 = 1 + (x1 > x0 ? x1 : x0);
  regs->y0 = y0 < y1 ? y0 : y1;
  regs->y1 = 1 + (y1 > y0 ? y1 : y0);
  regs->base = fb_base;
  regs->xstride = SDRAM_BUS_BITS/8;
  regs->ystride = FRAME_PITCH;
  regs->rgba = rgba;

  if(sw_render)
  {
    //printf("sw_rectangle_fill\n");
    sw_rectangle_fill(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return (abs(x1-x0)+1)*(abs(y1-y0)+1);
}

unsigned accel_ellipse_fill(accel_ellipse_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_ellipse_fill32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stops
    while(regs->done); //wait data latch
  }

  fb_base += (y0<y1?y0:y1)*FRAME_PITCH + (x0<x1?x0:x1)*sizeof(rgba);

  regs->x0 = x0 < x1 ? x0 : x1;
  regs->x1 = 1 + (x1 > x0 ? x1 : x0);
  regs->y0 = y0 < y1 ? y0 : y1;
  regs->y1 = 1 + (y1 > y0 ? y1 : y0);
  regs->base = fb_base;
  regs->xstride = SDRAM_BUS_BITS/8;
  regs->ystride = FRAME_PITCH;
  regs->rgba = rgba;
  
  if(sw_render)
  {
    //printf("sw_ellipse_fill\n");
#ifdef INDUCE_RENDERING_ERRORS    
    ++regs->y1;
#endif
    sw_ellipse_fill(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return (abs(x1-x0)+1)*(abs(y1-y0)+1);
}

unsigned accel_line(accel_line32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_line32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stops
    while(regs->done); //wait data latch
  }

  fb_base += y0*FRAME_PITCH + x0*sizeof(rgba);
  regs->x0 = x0;
  regs->x1 = x1;
  regs->y0 = y0;
  regs->y1 = y1;

  regs->base = fb_base;
  regs->xstride = x0 < x1 ? SDRAM_BUS_BITS/8 : -SDRAM_BUS_BITS/8;
  regs->ystride = y0 < y1 ? FRAME_PITCH : -FRAME_PITCH;

  regs->rgba = rgba;
  
  if(sw_render)
  {
    //printf("sw_line\n");
#ifdef INDUCE_RENDERING_ERRORS    
    ++regs->y1;
#endif
    sw_line(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return abs(x1-x0)+abs(y1-y0);
}


unsigned accel_rectangle(accel_line32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  return accel_line(regs, x0, y0, x1, y0, rgba)
   + accel_line(regs, x1, y0, x1, y1, rgba)
   + accel_line(regs, x1, y1, x0, y1, rgba)
   + accel_line(regs, x0, y1, x0, y0, rgba);
}


