// Copyright (C) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __SIM_FB_H__
#define __SIM_FB_H__

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

typedef struct
{
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
} fb_handle_t;

int fb_init(unsigned width, unsigned height, int vsync, fb_handle_t *handle);
void fb_update(fb_handle_t *handle, const void *buf, size_t stride_bytes);
void fb_deinit(fb_handle_t *handle);
int fb_should_quit(void);  

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C" 
#else
#define EXTERN_C
#endif
#endif

EXTERN_C uint64_t SDL_GetPerformanceCounter(void);
EXTERN_C uint64_t SDL_GetPerformanceFrequency(void);
static inline uint64_t higres_ticks(void) { return SDL_GetPerformanceCounter(); }
static inline uint64_t higres_ticks_freq(void) { return SDL_GetPerformanceFrequency(); }

#endif //__SIM_FB_H__
