// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#ifndef DISABLE_HARDWARE_ACCEL
#ifdef VIDEO_FRAMEBUFFER_HRES
#define FRAME_WIDTH VIDEO_FRAMEBUFFER_HRES
#else
#error VIDEO_FRAMEBUFFER_HRES not defined
#endif
#ifdef VIDEO_FRAMEBUFFER_VRES
#define FRAME_HEIGHT VIDEO_FRAMEBUFFER_VRES
#else
#error VIDEO_FRAMEBUFFER_VRES not defined
#endif
#ifndef VIDEO_FRAMEBUFFER_BASE
#error VIDEO_FRAMEBUFFER_BASE not defined
#endif
#else
//DISABLE_HARDWARE_ACCEL  defined
#ifndef FRAME_WIDTH
#define FRAME_WIDTH 1366
#define FRAME_HEIGHT 768
#endif
extern unsigned long VIDEO_FRAMEBUFFER_BASE;
#endif

#define FRAME_PITCH (FRAME_WIDTH<<2)


#define rgba2raw(r, g, b, a) ((r&255) | ((g&255)<<8) | ((b&255)<<16) | ((a&255)<<24))
#define alpha_mul(x, a) (((a)*(x))>>8) //factor is ideally 1 to 256 both inclusive

#endif
