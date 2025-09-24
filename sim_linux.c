// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <assert.h>
#include <stdint.h>

#include "graphics.h"

typedef union {
  uint32_t rgba;
  struct { uint32_t r:8; uint32_t g:8; uint32_t b:8; uint32_t a:8; };
} pix_t;

pix_t fb[FRAME_HEIGHT][FRAME_WIDTH];
unsigned long VIDEO_FRAMEBUFFER_BASE = (unsigned long) &fb;

#include "accel_cores.c"
#include "sim_fb.c"

#if defined (CSR_ACCEL_RECTANGLE_FILL32_BASE) \
	|| defined(CSR_ACCEL_LINE32_BASE) \
	|| defined(CSR_ACCEL_LINE32A_BASE) \
	|| defined(CSR_ACCEL_BLIT32_BASE) \
	|| defined(CSR_ACCEL_ELLIPSE_FILL32_BASE)
#error Accelerators should be disabled
#endif

fb_handle_t fbh;

void graphics_app(void);
void wait_vsync(void)
{
  fb_update(&fbh, fb, sizeof(fb[0]));
  if(fb_should_quit(/*&fbh*/))
  	exit(0);
}

int main()
{
	assert(sizeof(VIDEO_FRAMEBUFFER_BASE) == sizeof(void*));
	
  fb_init(FRAME_WIDTH, FRAME_HEIGHT, 0, &fbh); //set pix_vblank parameter to true to limit FPS
  
  while(!fb_should_quit(/*&fbh*/))
  {
    graphics_app();
    wait_vsync();
  }

  return 0;
}

