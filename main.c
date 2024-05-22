// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <irq.h>
#include <uart.h>

#include "misc.h" //just for ACCEL_STATIC_ASSERT
#include "accel_cores.h"
#include "graphics.h"
#include "fat_io_lib/src/fat_filelib.h"

//info timings
#define TURN_ATTENTION_TIME 3
#define TURN_FIRST_DISPLAY_TIME 15
#define TURN_RECALL_TIME 9
#define TURN_UPDATE_DISPLAY_TIME 5
#define INFO_MAX_TIME 30

//digit coordinates
#define BOX_X 450
#define TURN_X 175
#define DIGITS_SEP 95
#define DIGITS_Y 138
#define MOVIE_FPS 30

static uint64_t highres_ticks(void)
{
  timer0_uptime_latch_write(1);
  return timer0_uptime_cycles_read(); //makes increasing
}

static uint64_t highres_ticks_freq(void) { return CONFIG_CLOCK_FREQUENCY; }

typedef union
{
  uint32_t rgba;
  struct { uint32_t r:8; uint32_t g:8; uint32_t b:8; uint32_t a:8; };
} pix_t;


//TODO: use uncached regions of memory whenever possible
void flush_cache_region(void *buf, size_t size)
{
  flush_cpu_dcache();
  flush_l2_cache();
}

uint8_t *const video_buf = (uint8_t *) VIDEO_FRAMEBUFFER_BASE;
const unsigned stride = VIDEO_FRAMEBUFFER_HRES*(VIDEO_FRAMEBUFFER_DEPTH/8);


void wait_vsync(int count)
{
  flush_cache_region(video_buf, VIDEO_FRAMEBUFFER_VRES*stride); //only needed for software renderers
  uint32_t video_dma;
  while(count--)
  {
    do video_dma = video_framebuffer_dma_offset_read(); while (video_dma == 0); //avoid using first row
    while(video_framebuffer_dma_offset_read() >= video_dma);
  }
}

static uint8_t *jpeg_buf[2] = {NULL, NULL};
int show_movie_frame(FL_FILE *a, const char *fname, size_t flen)
{
    //printf("show_movie_frame: %s, len %u\n", fname, flen);
  
	static int buf_idx = 0;
	static int fcount = 0;
	
    free(jpeg_buf[buf_idx]);

    jpeg_buf[buf_idx] = (uint8_t *) malloc((flen + 0xFFFF) & 0xFFFF0000);
	int fr = fl_fread(jpeg_buf[buf_idx], flen, 1, a);
	if(fr != flen)
	{
		printf("Error reading data: read returns %d\n\n", fr);
		return -1;
	}
	flush_cache_region(jpeg_buf[buf_idx], flen);

	int frame_width=640, frame_height=480;
	size_t voff = (VIDEO_FRAMEBUFFER_HRES-frame_width)/2*(VIDEO_FRAMEBUFFER_DEPTH/8)+stride*((VIDEO_FRAMEBUFFER_VRES-frame_height)/2);
	accel_jpeg_decode(jpeg_buf[buf_idx], flen, video_buf+voff, stride, NULL, NULL, fcount++==0);
	++buf_idx;
	if(buf_idx>=2) buf_idx=0;
	
	return 0;
}

struct
{
  void *buffer;
  size_t size;
} default_font_atlas[256];

int load_default_font_char(FL_FILE *a, const char *fname, size_t flen)
{
  int ch = atoi(fname);
  if(ch < 0 || ch >= sizeof(default_font_atlas)/sizeof(default_font_atlas[0]))
  {
    printf("Ignoring char number %d\n", ch);
    return 0;
  }

  void *buf = malloc(flen);
  if(buf && fl_fread(buf, flen, 1, a) != flen)
  {
    printf("Error reading font atlas\n");
    return -1;
  }
  flush_cache_region(buf, flen);
  default_font_atlas[ch].buffer = buf;
  default_font_atlas[ch].size = flen;

  printf("read atlas char %d '%c', buf %p, len %d\n", ch, ch, buf, flen);
  return 0;
}

#include "untar.c"

void plot_digit(int x, int y, uint8_t ch)
{
    void *img_buf = default_font_atlas[ch].buffer;
    size_t len = default_font_atlas[ch].size;
    if(img_buf)
    {
      size_t voff = x*(VIDEO_FRAMEBUFFER_DEPTH/8)+stride*y;
      accel_bmp_decode(img_buf, len, video_buf+voff, stride, NULL, NULL, 1);
    }
}

void plot_number(int x, int y, unsigned n, int digits)
{
  while(digits--)
  {
    plot_digit(x, y, '0' + n % 10);
    n /= 10;
    x -= 120;
  }
}

void draw_background(void)
{
  static void *bk_buf = NULL;
  static size_t flen;
  if(bk_buf == NULL)
  {
    printf("opening background file\n");
    FL_FILE *bk = fl_fopen("/background.jpeg", "rb");
    if(bk)
    {
      flen = bk->filelength;
      bk_buf = malloc(flen);
	  if(bk_buf && fl_fread(bk_buf, flen, 1, bk) != flen)
	  {
	    free(bk_buf);
	    bk_buf = NULL;
	  }
	  flush_cache_region(bk_buf, flen);

      fl_fclose(bk);
      printf("file size %d, buf %p\n", flen, bk_buf);
    }
    else
      printf("unable to open background\n");
  }

  if(bk_buf)
  {
    wait_vsync(1);
	accel_jpeg_decode(bk_buf, flen, video_buf, stride, NULL, NULL, 0);
    //printf("drawing image background at %p, len %u\r", bk_buf, flen); //FIXME: why needs this delay
    wait_vsync(1);
    accel_jpeg_decode_waitdone(NULL, NULL); //wait
  }
}

int is_movie(const char *filename)
{
    const char suffix[] = {".jpeg.tar"};
    size_t len_filename = strlen(filename);

    if (len_filename < sizeof(suffix)) //base name of len at least 1
        return 0;

    return strcmp(filename + len_filename - (sizeof(suffix)-1), suffix) == 0;
}

int show_info(int frame)
{
  static FL_FILE *movie = NULL;
  static FL_DIR dirstat = { .cluster = FAT32_INVALID_CLUSTER };

  if(frame == 0 && movie) //restart
  {
     fl_fclose(movie);
     movie = NULL;
  }
  
  if(!movie)
  {
    printf("\n" "start info" "\n");

    if(dirstat.cluster == FAT32_INVALID_CLUSTER)
      fl_opendir("/videos/", &dirstat);

    while (dirstat.cluster != FAT32_INVALID_CLUSTER)
    {
      struct fs_dir_ent dirent;
      if (fl_readdir(&dirstat, &dirent) != 0)
      {
        fl_closedir(&dirstat);
        dirstat.cluster = FAT32_INVALID_CLUSTER;
        break;
      }

      if(!dirent.is_dir)
      {
        if(is_movie(dirent.filename))
        {
          char fullname[FATFS_MAX_LONG_FILENAME] = {"/videos/"};
          strncpy(fullname+8, dirent.filename, sizeof(fullname)-1);
          printf("Opening movie %s, size %lu\n", fullname, dirent.size);

          if(movie)
            fl_fclose(movie);
          movie = fl_fopen(fullname, "rb");
          if(movie)
            break;
          else
            printf("failed to open movie\n");
        }
      }
    }
  }
  else if(untar(movie, show_movie_frame) <= 0)
  {
    printf("\nmovie end\n");
    fl_fclose(movie);
    movie = NULL;
    return 0;
  }

  return 1;
}

void ring_bell(void)
{
  printf("\n" "next turn, ring bell!" "\n");
}

void load_font_atlas(void)
{
  FL_FILE *digit_atlas = NULL;
  {
    digit_atlas = fl_fopen("/atlas120x240.bmp.tar", "rb");
    if(digit_atlas)
    {
      while(untar(digit_atlas, load_default_font_char) > 0);
      fl_fclose(digit_atlas);
      printf("closing digit atlas\n");
    }
    else
      printf("Error opening digit atlas\n");
  }
}

void turn_machine(void)
{
  static int box=-1, turn=0, inactive=0, active=0; //active and inactive refer to the alternate info

  {
    int attention = inactive > (TURN_FIRST_DISPLAY_TIME - TURN_ATTENTION_TIME)*MOVIE_FPS; //at start
    attention |= inactive < TURN_ATTENTION_TIME*MOVIE_FPS; //before info
    if(uart_read_nonblock()) //check if something is received
    {
      int turn_prev = turn;
      char ch = uart_read();
      if(ch >= '0' && ch <= '9')
      {
        if(inactive == 0 || !attention) //ignore box requests too close to last one
        {
          if(box >= 0 && ++turn >= 100) turn = 0; //increment turn if there was a previous box
          ring_bell();
          box = ch-'0';
          inactive = TURN_FIRST_DISPLAY_TIME*MOVIE_FPS;
        }
      }
      else if(ch == '-')
      {
        if(turn == 0) turn = 100;
        --turn;
        inactive = TURN_UPDATE_DISPLAY_TIME*MOVIE_FPS;
      }
      else if(ch == '+')
      {
        if(++turn >= 100) turn = 0;
        inactive = TURN_UPDATE_DISPLAY_TIME*MOVIE_FPS;
      }
      else
      {
        inactive = 0;
        box = -1;
      }
      printf("box %d, turn %2d, inactive %3d, active %3d\n", box, turn, inactive, active);
    }
 
    if(inactive == 0)
    {
      if(active >= INFO_MAX_TIME*MOVIE_FPS || !show_info(active++))
      {
        if(box >= 0)
          inactive = TURN_RECALL_TIME*MOVIE_FPS;
        else
          active = 0; //show other info
      }
    }
    else
    {
      if(active > 0)
      {
        active = 0;
        draw_background();
      }

      plot_number(TURN_X, DIGITS_Y, turn, 2);
      if(box >= 0)
      {
        //box blinking logic
        if(!attention || (TURN_FIRST_DISPLAY_TIME*MOVIE_FPS-inactive) & 0x8)
          plot_number(BOX_X, DIGITS_Y, box, 1);
        else
          plot_digit(BOX_X, DIGITS_Y, ' ');
      }

      --inactive;
    }
    
  }
  
  //wait for next frame
  static uint64_t t0 = 0;
  int64_t dt;
  for(;;)
  {
    dt = highres_ticks() - t0;
    if(dt > highres_ticks_freq() / MOVIE_FPS)
      break;
    wait_vsync(1);
  }
  t0 += dt;
}

int fat_io_init(void);

int main(int argc, char **argv)
{
  irq_setmask(0);
  irq_setie(1);

  uart_init();

  if (fat_io_init() != FAT_INIT_OK)
    printf("ERROR: Failed to init file system\n");

  load_font_atlas();
  for(;;)
    turn_machine();

  irq_setie(0);
  irq_setmask(~0);
    
  return 0;
}

void isr_handler(void)
{
  __attribute__((unused)) unsigned int irqs;
  irqs = irq_pending() & irq_getmask();

#ifndef UART_POLLING
  if(irqs & (1 << UART_INTERRUPT))
    uart_isr();
#endif
}

// helpers -----------------------------------------------------------------------------------------
void _putchar(char c) { uart_write(c); } //this is to make printf work

void assert(int c)
{
  if(c)
    return;
  printf("ASSERTION FAILURE\n");
  for(;;);
}

