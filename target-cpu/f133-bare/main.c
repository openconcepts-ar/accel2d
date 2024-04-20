// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>
#include <string.h>
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

extern uint8_t jpeg_test_image_640x480_data[];
extern unsigned jpeg_test_image_640x480_data_len;

//#define TJPGD_DEMO

#ifdef TJPGD_DEMO
#include "../../tjpgd3/jpeg_demo.c"
#include "../../tjpgd3/src/tjpgd.c"
static void jpeg_decompress(void)
{
	static uint8_t work[16384];
	static uint32_t fbdata[480][640];
	IODEV devid; // Session identifier
	devid.fp = jpeg_test_image_640x480_data;
	devid.fbuf = (uint8_t *) fbdata;
	devid.wfbuf = 640;
	JRESULT res = jpeg_demo(&devid, work, sizeof(work));
	if(res == JDR_OK)
		framebuffer_address = (uintptr_t) fbdata;
}
#else

int ultraembedded_jpeg_decompress(const uint8_t *jpegdata, size_t jpegdata_size, uint8_t *dst);

static void jpeg_decompress(void)
{
	static uint32_t fbdata[480][640];
	if(ultraembedded_jpeg_decompress(jpeg_test_image_640x480_data, jpeg_test_image_640x480_data_len, (uint8_t *) fbdata) == 0)
		framebuffer_address = (uintptr_t) fbdata;
}

#endif
#endif


int main(void)
{
  printf("Decompressing JPEG...\r\n");
  jpeg_decompress();
  printf("Done\r\n");

  if(framebuffer_address)
  {
    void fb_probe(void);
    fb_probe();
  }
  
#if 0
  uint64_t t0 = highres_ticks();
  size_t nbytes = 0;
  for(int i=0; ; ++i)
  {
    //printf("Hello from D1s bare %d!!\r\n", i);
    for(int y=0; y < 480; ++y)
    {
      memset((void*)(framebuffer_address+y*640*4), i, (640-1)*4);
      nbytes += (640-1)*4;
    }

    if((i & 0xFF) == 0)
    {
      uint64_t t1 = highres_ticks();
      printf("bytes %d, dt %d ms\r\n", nbytes, 1000*(t1-t0)/highres_ticks_freq());
      jpeg_decompress();
      t0 = highres_ticks();
      nbytes = 0;
    }

    io_write32(GPIO_pd_dat, i & 128 ? led_mask : 0);
  }
#else
  for(;;);  
#endif
  return 0;
}


void __assert_fail(void)
{
  printf("ASSERTION FAILED\r\n");
  for(;;);
}

