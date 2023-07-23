//(C) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "cflexhdl.h"
#include "bus.h"
#include "graphics.h"

MODULE rectangle_fill32(
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
  busaddr_t yaddr;
  uint16 x, y;

  bus_setup32();
  yaddr = base;
  
  for(y = y0; y < y1; y = y + 1)
  {
    bus_set_address(yaddr);
    for(x = x0; x < x1; )
    {
      bus_write_start(rgba);
        
      if(!bus_write_pending())
      {
        bus_stop();
        bus_inc_address(xstride);
        x = x + 1;
      }
    }
    while(bus_write_pending());
    bus_release();
    yaddr = yaddr + ystride;
  }
}

