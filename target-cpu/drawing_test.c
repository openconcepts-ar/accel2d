// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#define RAND_SEED 0xABCDEF
static uint32_t lfsr = RAND_SEED; //won't work until suitable seed is set
void srand32(uint32_t seed)
{
  lfsr = seed;
}


uint32_t rand32(void)
{
  const uint32_t POLY_MASK = 0xB4BCD35C;

  int feedback = lfsr & 1;
  lfsr >>= 1;
  if (feedback)
    lfsr ^= POLY_MASK;
  return lfsr;
}

void flush_caches()
{
#if defined(FRAMEBUFFER_CACHE_HANDLING) && !defined(CSR_ACCEL_RECTANGLE_FILL32_BASE) && defined(CSR_ACCEL_ELLIPSE_FILL32_BASE)
  flush_l2_cache(); //corrects screen pixels
  flush_cpu_dcache();
#endif
}

// drawing tests -----------------------------------------------------------------------------------


void draw_char(char ch, int x, int y, int width, int height, uint32_t rgba)
{
  if(ch == ':')
  {
    int x0 = x+4*width;
    int y0 = y+2*height;
    accel_ellipse_fill32(VIDEO_FRAMEBUFFER_BASE, x0, y0, x0+2*width, y0+4*height, rgba, FRAME_PITCH);
    y0 += 6*width;
    flush_caches();
    accel_ellipse_fill32(VIDEO_FRAMEBUFFER_BASE, x0, y0, x0+2*width, y0+4*height, rgba, FRAME_PITCH);
    return;
  }

  if(ch == '.')
  {
    int x0 = x+4*width;
    int y0 = y+12*height;
    flush_caches();
    accel_ellipse_fill32(VIDEO_FRAMEBUFFER_BASE, x0, y0, x0+2*width, y0+2*height, rgba, FRAME_PITCH);
    return;
  }
  
  if(ch < '0' || ch > '9')
    return;
 
  /*
    012345
     WWWW  0
    WW  WW 2
    WW  WW 4
     WWWW  6
    WW  WW 8
    WW  WW 10
     WWWW  12
 */
  
  struct segment
  {
    const char *mask;
    int x, y, w, h;
  } const segments[7]={
    {"1011011111", 1,  0, 4, 2}, //A (top)
    {"1111100111", 4,  1, 2, 6}, //B (top right)
    {"1101111111", 4,  7, 2, 6}, //C (bottom right)
    {"1011011011", 1, 12, 4, 2}, //D (bottom)
    {"1010001010", 0,  7, 2, 6}, //E (bottom left)
    {"1000111011", 0,  1, 2, 6}, //F (top left)
    {"0011111011", 1,  6, 4, 2}, //G (middle)
  };
  const struct segment *s = segments;
  for(int i=0; i < 7; ++i, ++s)
  {
    if(s->mask[ch-'0'] != '0')
    {
      int x0 = x+width*s->x;
      int y0 = y+height*s->y;
      int x1 = x0+width*s->w;
      int y1 = y0+height*s->h;
      if(x0 >= 0 && x1 < FRAME_WIDTH && y0 >= 0 && y1 < FRAME_HEIGHT)
      {
       //FIXME: recheck condition...
        flush_caches();
        accel_rectangle_fill32(VIDEO_FRAMEBUFFER_BASE, x0, y0, x1, y1, rgba, FRAME_PITCH);
      }
    }
  }

  struct corner
  {
    const char *mask;
    int x, y, w, h;
  } const corners[6]={
    {"1000111011", 0,  0, 2, 2}, //top-left
    {"1011000111", 4,  0, 2, 2}, //top-right
    {"0010011000", 4,  6, 2, 2}, //center-right
    {"1001011011", 4, 12, 2, 2}, //bottom-right
    {"1010001010", 0, 12, 2, 2}, //bottom-left
    {"0010110001", 0,  6, 2, 2}, //center-left
  };
  const struct corner *c = corners;
  for(int i=0; i < 6; ++i, ++c)
  {
    if(c->mask[ch-'0'] != '0')
    {
      int x0 = x+width*c->x;
      int y0 = y+height*c->y;
      int x1 = x0+width*c->w;
      int y1 = y0+height*c->h;
      if(x0 >= 0 && x1 < FRAME_WIDTH && y0 >= 0 && y1 < FRAME_HEIGHT)
      {
        accel_ellipse_fill32(VIDEO_FRAMEBUFFER_BASE, x0, y0, x1, y1, rgba, FRAME_PITCH);
      }
    }
  }
  
  //accel_rectangle(x-2, y-2, x+width*6+2, y+height*15-5, rgba); //optionally draw some lines around digits
}

int draw_clock(uint32_t bkcolor)
{
  static uint64_t ttarget;
  static int init = 0;
  if(!init)
  {
    ttarget = highres_ticks();
    init=1;
    accel_rectangle_fill32(VIDEO_FRAMEBUFFER_BASE, 0, 0, FRAME_WIDTH-1, FRAME_HEIGHT-1, bkcolor, FRAME_PITCH);
    srand32(RAND_SEED);
  }
#define DIGITS 7 //7, 9 or 10
  int64_t dt = highres_ticks() - ttarget;
  const uint64_t period = highres_ticks_freq()/(DIGITS == 10 ? 100 : DIGITS == 9 ? 10 : 1);
  
  static char timedigits[11]=
  { //01234567890
    //XX:XX:XX.00
    __TIME__ ".00"
  };
  
  static int x0 = 10, y0 = 350;
  static int dx = 1, dy = 1;
  const int sz = 7;
  if(dt >= 0)
  {
    ttarget += period;

    int incr = 1;

    // 0123456789012345
    // XXYY:XXYY:XXYY.ZZZZ
    static const int pos[11]={0,2,3, 5,7,8, 10,12,13, 15,17};
    uint32_t color = rand32() | 0xFF004000;
    
    for(int i = DIGITS; i >= 0; --i) //9 for 1/10th seconds, 10 for 1/100th seconds
    {
      int isnum = timedigits[i] >= '0' && timedigits[i] <= '9';
      if(incr && isnum)
      {
        char ovf = (i==6 || i==3) ? '5':'9'; //overflow value (decimal or sexagesimal)
        if(timedigits[i] == ovf)
          timedigits[i]='0';
        else
        {
          ++timedigits[i];
          incr = 0; //stop carry
        }
      }
      int x = x0+pos[i]*4*sz;
      int y = y0;
      if(isnum) //FIXME: to avoid problems with superposition of characters, all previous digits should be drawn prior to current ones
        draw_char('8', x-dx, y-dy, sz, sz, bkcolor); //clear previous digit
      else
        draw_char(timedigits[i], x-dx, y-dy, sz, sz, bkcolor); //clear previous symbol

      //if(timedigits[i]==':')
      //  color = timedigits[9]<'5' ? 0xFFC0C0C0 : bkcolor;
      draw_char(timedigits[i], x, y, sz, sz, color);
    }
    const int xlimit = FRAME_WIDTH-(pos[DIGITS]*4+7)*sz;
    const int ylimit = FRAME_HEIGHT-sz*(14+1);
#if DIGITS == 7
    int x0_new = ((uint32_t)ttarget*37*41) % xlimit; //random like
    int y0_new = ((uint32_t)ttarget*43*67) % ylimit; //random like
    dx = x0_new-x0; 
    dy = y0_new-y0;
#else
    //bouncing
    if(x0 >= xlimit)
      dx = -1;
    if(x0 <= 0)
      dx = 1;
    if(y0 >= ylimit)
      dy = -1;
    if(y0 <= 1*sz)
      dy = 1;
#endif
    x0 += dx;
    y0 += dy;


    flush_caches();
    return 1;
  }
  return 0;
}

