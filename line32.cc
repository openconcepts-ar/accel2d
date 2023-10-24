//(C) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "cflexhdl.h"
#include "bus.h"
#include "graphics.h"

#ifndef iabs
#warning iabs should be defined
#define iabs(x) ((x) < 0 ? -(x) : (x))
#endif

MODULE line32(
  bus_master(bus),
  const uint16&	x0,
  const uint16&	x1,
  const uint16&	y0,
  const uint16&	y1,
  const uint32&	rgba, //color
  const uint32& base, //pixel offset
  const int16& xstride, //normally 1, but can run backwards
  const int16& ystride //bytes to skip for next line (usually the framebuffer width * 4 bytes)
  )
{

  bus_setup32();

  //signed coordinates
  int16 x0i = x0;
  int16 x1i = x1;
  int16 y0i = y0;
  int16 y1i = y1;
 

  int16 dx =  iabs (x1i - x0i);
  int16 dy = -iabs (y1i - y0i);
  int2 sx = x0 < x1 ? 1 : -1;
  int2 sy = y0 < y1 ? 1 : -1;
  int16 err = dx + dy; /* error value e_xy */
  int16 x = x0;
  int16 y = y0;
  int16 e2;
  
 
  bus_set_address(base);
  while(x != x1 || y != y1)
  {
    bus_write_start(rgba);

    if(!bus_write_pending())
    {
      bus_stop();
      
      //these variables needs to be signed
      busaddr_diff_t xincaddr = 0; 
      busaddr_diff_t yincaddr = 0;
      
      e2 = err << 1;

      int16 dxe = 0;
      if (e2 <= dx) // e_xy+e_y < 0
      {
        dxe = dx;
        y = y + sy;
        yincaddr = ystride;
      } 

      int16 dye = 0;
      if (e2 >= dy) // e_xy+e_x > 0
      {
        dye = dy;
        x = x + sx;
        xincaddr = xstride;
      }
      bus_inc_address(xincaddr + yincaddr);
      err = err + dxe + dye;
    }
  }
  while(bus_write_pending()); //wait last transaction
  bus_release();
}
