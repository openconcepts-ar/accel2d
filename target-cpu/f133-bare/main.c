// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>
#include "ioregs.h"
#include "sys.h"
#include "sw_accel_cores.h"

#define LED_BUILTIN 22
static const uint32_t led_mask = 1 << LED_BUILTIN;

extern uintptr_t framebuffer_address;
extern unsigned framebuffer_pitch;

#if 0
static void graphics_test(void)
{
	int x0 = 100, x1 = 300;
	int y0 = 100, y1 = 300;
	accel_line32(framebuffer_address, 0, 100, 100, 0, 0xFF0000FF, framebuffer_pitch); //red
	accel_ellipse_fill32(framebuffer_address, x0, y0+300, x1, y0+350, 0xFFFF0000, framebuffer_pitch); //blue
	accel_rectangle_fill32(framebuffer_address, x0+400, y0+300, x1+300, y0+350, 0xFF00FF00, framebuffer_pitch); //green
}
#else
unsigned FRAME_WIDTH, FRAME_HEIGHT, FRAME_PITCH;
uintptr_t VIDEO_FRAMEBUFFER_BASE;

#define highres_ticks_freq() (F_XTAL/24)
#define highres_ticks() (cpu_count()/24)

#include "../drawing_test.c"
static void graphics_test(void)
{
  VIDEO_FRAMEBUFFER_BASE = framebuffer_address;
  FRAME_WIDTH = 640 - 1; //FIXME: this correction is to make colors = 0 for analog VGA
  FRAME_HEIGHT = 480;
  FRAME_PITCH = framebuffer_pitch;
  for(;;)
    draw_clock(0xFFFF8000);
}
#endif

int main(void)
{
  void fb_probe(void);
  fb_probe();
  

  for(int i=0; ; ++i)
  {
    if(i < 10)
      printf("Hello from D1s bare %d!!\r\n", i);
    else
       graphics_test();

    io_write32(GPIO_pd_dat, i & 1 ? led_mask : 0);

    delay_us(500*1000);
  }
  return 0;
}

