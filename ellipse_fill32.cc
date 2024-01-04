//(C) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "cflexhdl.h"
#include "bus.h"
#include "graphics.h"

MODULE ellipse_fill32(
  bus_master(bus),
  const uint16&	x0,
  const uint16&	x1,
  const uint16&	y0,
  const uint16&	y1,
  const uint32&	rgba, //color
  const busaddr_t& base, //pixel offset
  const int16& xstride, //normally 4, but can run backwards
  const int16& ystride //bytes to skip for next line (usually the framebuffer width * 4 bytes)
  )
{
  busaddr_t yaddr;

  int16 x, y, rw, rh;
  int32 xx, yy, ww, hh;
  int64 xh, yw, wh;

  bus_setup32();
  rh = (y1 - y0) >> 1;
  rw = (x1 - x0) >> 1;
  ww = rw*rw;
  hh = rh*rh;
  wh = promote_u64(ww)*promote_u64(hh);
  
  yaddr = base;
  
  y = -rh;
  while(y < rh)
  {
    bus_set_address(yaddr);
    yy = y*y;
    yw = promote_u64(yy)*promote_u64(ww);
    x = -rw;
    while(x < rw)
    {
      xx = x*x;
      xh = promote_u64(xx)*promote_u64(hh);
      if(xh + yw < wh)
      {
        //point lies inside
        bus_write_start(rgba);
        
        if(!bus_write_pending())
        {
          bus_stop();
          bus_inc_address(xstride);
          x = x + 1;
        }
      }
      else
      {
        bus_inc_address(xstride);
        x = x + 1;
      }
    }
    while(bus_write_pending()); //wait last transaction
    bus_release();
    yaddr = yaddr + ystride;
    y = y + 1;
  }
}

