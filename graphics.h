// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#ifdef VIDEO_FRAMEBUFFER_HRES
#define FRAME_WIDTH VIDEO_FRAMEBUFFER_HRES
#else
#define FRAME_WIDTH 640
#endif
#ifdef VIDEO_FRAMEBUFFER_VRES
#define FRAME_HEIGHT VIDEO_FRAMEBUFFER_VRES
#else
#define FRAME_HEIGHT 480
#endif
#define FRAME_PITCH (FRAME_WIDTH<<2)

#ifndef VIDEO_FRAMEBUFFER_BASE
#define VIDEO_FRAMEBUFFER_BASE 0x40C00000 //default LiteX framebuffer memory address
#endif

#define rgba2raw(r, g, b, a) ((r) | ((g)<<8) | ((b)<<16) | ((a)<<24))

#define alpha_mul(x, a) (((a)*(x))>>8) //for more precision: (x * a + 1 + ((x * a) >> 8)) >> 8;

#define alpha_blend_i(r, r1, g, g1, b, b1, a_inv, a1) \
   rgba2raw(r + alpha_mul(r1, a_inv), \
            g + alpha_mul(g1, a_inv), \
            b + alpha_mul(b1, a_inv), \
            a1 - a_inv)

#endif
