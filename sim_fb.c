// Copyright (C) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <SDL2/SDL.h>
#include "sim_fb.h"

int fb_init(unsigned width, unsigned height, int vsync, fb_handle_t *handle)
{
    int texture_format;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
     return 0;

    handle->win = SDL_CreateWindow("Simulator window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!handle->win)
      return 0;

    handle->renderer = SDL_CreateRenderer(handle->win, -1, vsync ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC : 0);
    if (!handle->renderer)
      return 0;

    handle->texture = SDL_CreateTexture(handle->renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, width, height);
    if (!handle->texture)
      return 0;

    return 1;
}

int fb_should_quit(void)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
          case SDL_QUIT:
            return 1;
          case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
               return 1;
        }
    }
    return 0;
}

void fb_update(fb_handle_t *handle, const void *buf, size_t stride_bytes)
{
    SDL_UpdateTexture(handle->texture, NULL, buf, stride_bytes);
    SDL_RenderCopy(handle->renderer, handle->texture, NULL, NULL);
    SDL_RenderPresent(handle->renderer);
}

void fb_deinit(fb_handle_t *handle)
{
    SDL_DestroyTexture(handle->texture);
    SDL_DestroyRenderer(handle->renderer);
    SDL_DestroyWindow(handle->win);
    handle->win = NULL;
}
