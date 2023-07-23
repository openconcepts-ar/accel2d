// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <assert.h>
#include <stdint.h>

#include "graphics.h"

#define DISABLE_HARDWARE_ACCEL
typedef union {
  uint32_t rgba;
  struct { uint32_t r:8; uint32_t g:8; uint32_t b:8; uint32_t a:8; };
} pix_t;

pix_t fb[FRAME_HEIGHT][FRAME_WIDTH];
#undef VIDEO_FRAMEBUFFER_BASE
#define VIDEO_FRAMEBUFFER_BASE (intptr_t)(&fb[0][0].rgba)

#include "accel_cores.c"
#include "sim_fb.c"
#include "drawing_test.c"

#if defined (CSR_ACCEL_RECTANGLE_FILL32_BASE) || defined(CSR_ACCEL_ELLIPSE_FILL32_BASE)
#error Accelerators should be disabled
#endif

fb_handle_t fbh;

int main()
{
  fb_init(FRAME_WIDTH, FRAME_HEIGHT, 0, &fbh); //set pix_vblank parameter to true to limit FPS
  
  draw_shapes(1000);
  
  while(!fb_should_quit())
  {
    draw_clock();
    fb_update(&fbh, fb, sizeof(fb[0]));
  }

  return 0;
}

