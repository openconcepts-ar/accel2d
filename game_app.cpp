// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h> //printf()
#include <math.h>

#include "misc.h"
#include "graphics.h"
#include "accel_cores.h"

static intptr_t fbuf = 0;

//ImGUI compatibility, see https://github.com/ocornut/imgui/blob/master/imgui.h#L147
typedef int ImDrawFlags;
typedef uint32_t ImU32;
#define ImColor(...) 1

struct ImVec4 { float x, y, z, w; };
struct ImVec2 {
  float x, y;
  ImVec2() : x(0), y(0) {}
  ImVec2(float _x, float _y) : x(_x), y(_y) {}
  ImVec2(const ImVec2& a) : x(a.x), y(a.y) {}
  ImVec2& operator = (const ImVec2& a) { x = a.x; y = a.y; return *this; }
};

static inline ImVec2 operator*(const ImVec2& lhs, const float rhs)              { return ImVec2(lhs.x*rhs, lhs.y*rhs); }
static inline ImVec2 operator/(const ImVec2& lhs, const float rhs)              { return ImVec2(lhs.x/rhs, lhs.y/rhs); }
static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs)            { return ImVec2(lhs.x+rhs.x, lhs.y+rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs)            { return ImVec2(lhs.x-rhs.x, lhs.y-rhs.y); }
static inline ImVec2 operator*(const ImVec2& lhs, const ImVec2& rhs)            { return ImVec2(lhs.x*rhs.x, lhs.y*rhs.y); }
static inline ImVec2 operator/(const ImVec2& lhs, const ImVec2& rhs)            { return ImVec2(lhs.x/rhs.x, lhs.y/rhs.y); }
static inline ImVec2& operator+=(ImVec2& lhs, const ImVec2& rhs)                { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
static inline ImVec2& operator-=(ImVec2& lhs, const ImVec2& rhs)                { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
static inline ImVec2& operator*=(ImVec2& lhs, const float rhs)                  { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const float rhs)                  { lhs.x /= rhs; lhs.y /= rhs; return lhs; }


struct ImDrawList
{
  //see API https://github.com/ocornut/imgui/blob/master/imgui.h#L3098

  void AddCircleFilled(const ImVec2& center, float radius, ImU32 col, int num_segments = 0)
  {
    if(radius<=1)
     return;
    printf("AddCircleFilled (%d,%d) r=%d\n", int(center.x), int(center.y), int(radius));
  }

  void AddRectFilled(const ImVec2& p_min, const ImVec2& p_max, ImU32 col, float rounding = 0.0f, ImDrawFlags flags = 0)
  {
    //printf("AddRectFilled (%d,%d)-(%d,%d) color 0x%08lX\n", int(p_min.x), int(p_min.y), int(p_max.x), int(p_max.y), uint32_t(col));
    int x0 = p_min.x, x1 = p_max.x, y0 = p_min.y, y1 = p_max.y;
    if(x1 < x0)
      return;
    if(y1 < y0)
      return;
    if(x0 < 0) 
      x0 = 0;
    if(x1 >= FRAME_WIDTH) 
      x1 = FRAME_WIDTH-1;
    if(y0 < 0) 
      y0 = 0;
    if(y1 >= FRAME_HEIGHT) 
      y1 = FRAME_HEIGHT-1;

    //accel_rectangle_fill(rectangle_regs, x0, y0, x1, y1, col);
    uint32_t *dst_base = (uint32_t *) (fbuf + y0*FRAME_PITCH);
    dst_base += x0;
    blit32(dst_base, FRAME_WIDTH, nullptr, 0, x1-x0+1, y1-y0+1, 0, col);
  }

};

__attribute__((weak)) void FX_init(void);
#include "game_app.inl"


extern "C" void wait_vsync(void);
void flip(void)
{
#ifdef VIDEO_FRAMEBUFFER_BASE
  //printf("current framebuffer %p\n", fbuf);

  uint32_t hline = video_framebuffer_dma_offset_read()/(FRAME_WIDTH/4);
#ifdef LITEX_SIMULATION
  printf("initial line %ld\t", hline);

  do
    hline = video_framebuffer_dma_offset_read()/(FRAME_WIDTH/4);
  while(hline > FRAME_HEIGHT); //last offset is FRAME_HEIGHT+1

  do
   hline = video_framebuffer_dma_offset_read()/(FRAME_WIDTH/4);
  while(hline <= FRAME_HEIGHT);
#endif

  video_framebuffer_dma_base_write(fbuf);
  fbuf = (fbuf != VIDEO_FRAMEBUFFER_BASE) ? VIDEO_FRAMEBUFFER_BASE : VIDEO_FRAMEBUFFER_BASE + 2*FRAME_HEIGHT*FRAME_PITCH;
#ifndef LITEX_SIMULATION
  do
    hline = video_framebuffer_dma_offset_read()/(FRAME_WIDTH/4);
  while(hline > FRAME_HEIGHT); //wait to restart
#endif
#else
  wait_vsync();
#endif
}


static ImDrawList d;
static ImVec2 a(0,0), b(FRAME_WIDTH-1, FRAME_HEIGHT-1);
static ImVec4 m{FRAME_WIDTH/2, FRAME_HEIGHT/2, -1, -1};
  

void draw_frame(double t)
{
    FX(&d, a, b, b-a, m, t);
    flip();
}

extern "C" void graphics_app(void)
{
  printf("Game demo\n");
  fbuf = VIDEO_FRAMEBUFFER_BASE;
  
  //fill background, both framebuffers
#ifdef BACKGROUND_COLOR
  //accel_rectangle_fill(rectangle_regs, 0, 0, FRAME_WIDTH, FRAME_HEIGHT*3, BACKGROUND_COLOR);
  //accel_rectangle_fill(rectangle_regs, 0, 0, FRAME_WIDTH, FRAME_HEIGHT*3, BACKGROUND_COLOR);
#ifndef DISABLE_HARDWARE_ACCEL
  blit32((uint32_t*)VIDEO_FRAMEBUFFER_BASE, FRAME_WIDTH, nullptr, 0, FRAME_WIDTH, FRAME_HEIGHT*3, 0, BACKGROUND_COLOR);
#else
  blit32((uint32_t*)VIDEO_FRAMEBUFFER_BASE, FRAME_WIDTH, nullptr, 0, FRAME_WIDTH, FRAME_HEIGHT, 0, BACKGROUND_COLOR);
#endif
#endif

  if(FX_init)
    FX_init();
  
  /*
void FX(ImDrawList* d, ImVec2 a, ImVec2 b, ImVec2 sz, ImVec4 mouse, float t);
     d : draw list
     a : upper-left corner
     b : lower-right corner
    sz : size (== b - a)
 mouse : x,y = mouse position (normalized so 0,0 over 'a'; 1,1 is over 'b', not clamped)
         z,w = left/right button held. <-1.0f not pressed, 0.0f just pressed, >0.0f time held.
    t  : time
      */
  float t = 0;
  float t0 = float(highres_ticks()) / highres_ticks_freq();
  for(;;)
  {
    draw_frame(t);

    float dt = float(highres_ticks()) / highres_ticks_freq() - t0;
    t += dt;
    printf("t %d, FPS %d\n", int(t), int(1./dt));
    t0 = t;
  }
}


