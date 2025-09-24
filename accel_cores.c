// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>
#include <stdlib.h> //abs
#include <string.h> //memcpy

#include "misc.h" //just for ACCEL_STATIC_ASSERT
#include "accel_cores.h"
#include "graphics.h"
#include "sw_cores.h"

#include "bmp.h"

//#define INDUCE_RENDERING_ERRORS //enable to induce errors in softwre renderer

unsigned accel_rectangle_fill(accel_rectangle_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_rectangle_fill32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_RECTANGLE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_RECTANGLE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stps
    while(regs->done); //wait data latch
  }


  fb_base += (y0<y1?y0:y1)*FRAME_PITCH + (x0<x1?x0:x1)*sizeof(rgba);
  regs->x0 = x0 < x1 ? x0 : x1;
  regs->x1 = 1 + (x1 > x0 ? x1 : x0);
  regs->y0 = y0 < y1 ? y0 : y1;
  regs->y1 = 1 + (y1 > y0 ? y1 : y0);
  regs->base = fb_base;
  regs->xstride = SDRAM_BUS_BITS/8;
  regs->ystride = FRAME_PITCH;
  regs->rgba = rgba;

  if(sw_render)
  {
    //printf("sw_rectangle_fill\n");
    sw_rectangle_fill(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return (abs(x1-x0)+1)*(abs(y1-y0)+1);
}

unsigned accel_ellipse_fill(accel_ellipse_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_ellipse_fill32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stops
    while(regs->done); //wait data latch
  }

  fb_base += (y0<y1?y0:y1)*FRAME_PITCH + (x0<x1?x0:x1)*sizeof(rgba);

  regs->x0 = x0 < x1 ? x0 : x1;
  regs->x1 = 1 + (x1 > x0 ? x1 : x0);
  regs->y0 = y0 < y1 ? y0 : y1;
  regs->y1 = 1 + (y1 > y0 ? y1 : y0);
  regs->base = fb_base;
  regs->xstride = SDRAM_BUS_BITS/8;
  regs->ystride = FRAME_PITCH;
  regs->rgba = rgba;
  
  if(sw_render)
  {
    //printf("sw_ellipse_fill\n");
#ifdef INDUCE_RENDERING_ERRORS    
    ++regs->y1;
#endif
    sw_ellipse_fill(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return (abs(x1-x0)+1)*(abs(y1-y0)+1);
}

unsigned accel_line(accel_line32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  accel_line32_layout_t sw_args;
  int sw_render = !regs;
  uintptr_t fb_base = VIDEO_FRAMEBUFFER_BASE; 
#ifdef VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32
  if(!sw_render) fb_base = VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32;
#endif
  if(sw_render)
    regs = &sw_args;
  else
  {
    regs->run = 0; //stops
    while(regs->done); //wait data latch
  }

  fb_base += y0*FRAME_PITCH + x0*sizeof(rgba);
  regs->x0 = x0;
  regs->x1 = x1;
  regs->y0 = y0;
  regs->y1 = y1;

  regs->base = fb_base;
  regs->xstride = x0 < x1 ? SDRAM_BUS_BITS/8 : -SDRAM_BUS_BITS/8;
  regs->ystride = y0 < y1 ? FRAME_PITCH : -FRAME_PITCH;

  regs->rgba = rgba;
  
  if(sw_render)
  {
    //printf("sw_line\n");
#ifdef INDUCE_RENDERING_ERRORS    
    ++regs->y1;
#endif
    sw_line(regs);
  }
  else
  {
    regs->run = 1; //start
    while(!regs->done); //wait until done
  }

  return abs(x1-x0)+abs(y1-y0);
}

unsigned accel_rectangle(accel_line32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba)
{
  return accel_line(regs, x0, y0, x1, y0, rgba)
   + accel_line(regs, x1, y0, x1, y1, rgba)
   + accel_line(regs, x1, y1, x0, y1, rgba)
   + accel_line(regs, x0, y1, x0, y0, rgba);
}

static void bmp32_invert_red_blue_channels(uint8_t *dst, uint8_t *src, int width)
{
    //memcpy(dst, src, width*sizeof(uint32_t));
    //return;

    while(width--)
    {
        //this type of access is ok with misaligmnents
        dst[0] = src[2];
        dst[1] = src[1];
        dst[2] = src[0];
        dst[3] = src[3];
        
        dst += 4;
        src += 4;
    }
}

//example command for PNG to BMP (32-bit)
//$ convert input.png -alpha on output.bmp
void accel_bmp_decode(const void *coded_buf, size_t coded_len, void *dst, unsigned writer_stride,
 unsigned *decoded_width, unsigned *decoded_height, int wait_done, int invert_rb)
{
  BMPHeader *bmp = (BMPHeader *) coded_buf;
  assert(bmp->type == 0x4D42);

  assert(bmp->bits_per_pixel == 32 && bmp->compression == 3); //check RGBA32 format
  unsigned w = bmp->width_px, h = bmp->height_px;

  if((decoded_width != NULL && w > *decoded_width) || (decoded_height != NULL && h > *decoded_height))
  {
     //not enough space
    printf("BMP not decoded: w %d, decoded_width %d, h %d, decoded_height %d\n", h, *decoded_width, w, *decoded_height);
    *decoded_width = 0;
    *decoded_height = 0;
    return;
  }
    
  const uint32_t *data = (uint32_t *)(((uint8_t*)bmp) + bmp->offset);
  
  uint8_t *fb = (uint8_t *) dst;
  data += h* w;
  while(h--)
  {
    data -= w;
    //printf("BMP lines remaining to decode %u, width %u - fb %p, data %p\n", h, w, fb, data);
    if(!invert_rb)
	    memcpy(fb, data, w*sizeof(uint32_t));
	else
	   bmp32_invert_red_blue_channels(fb, (uint8_t *) data, w);

    fb += writer_stride;
  }
  
  if(decoded_width) *decoded_width = bmp->width_px;
  if(decoded_height) *decoded_height = bmp->height_px;
}


#ifdef CSR_JPEG_DECODER_BASE
/*
Example converting a video file

wget http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi
ffmpeg -i big_buck_bunny_480p_surround-fix.avi -vf "scale=640:480" frame%05d.png
(for file in frame*.png; do convert "$file" ppm:- | cjpeg -quality 90 -sample 2x2 -baseline -outfile "${file%.png}.jpeg"; echo "${file%.png}.jpeg"; done;) | tar -T - -cvf big_buck_bunny_480p_surround-fix.jpeg.tar
rm frame*.png frame*.jpeg

At same resolution, resulting size is about 4X the original file (no audio)
*/

void accel_jpeg_decode(const void *coded_buf, size_t coded_len, void *dst, unsigned writer_stride,
 unsigned *decoded_width, unsigned *decoded_height, int wait_done)
{
  accel_jpeg_decode_waitdone(NULL, NULL);

  coded_len = (coded_len + 3) & ~3;
  jpeg_decoder_reader_base_write((intptr_t) coded_buf);
  jpeg_decoder_reader_length_write(coded_len);
  jpeg_decoder_writer_base_write((intptr_t) dst);
  jpeg_decoder_writer_stride_write(writer_stride);

  jpeg_decoder_reader_enable_write(1); //start decoding

  if(wait_done)
    accel_jpeg_decode_waitdone(decoded_width, decoded_height);
}

void accel_jpeg_decode_waitdone(unsigned *decoded_width, unsigned *decoded_height)
{
  int count = 0;
  while(!jpeg_decoder_idle_status_read())
  {
    if(count++>100)
    {
      jpeg_decoder_reader_enable_write(0);
      printf("DECODING ERROR\n");
      return;
    }
    printf("idle %ld, byte read offset %ld (of %d), write offset %ld (%d,%d)\n", jpeg_decoder_idle_status_read(),
    jpeg_decoder_reader_offset_read()*4, jpeg_decoder_reader_length_read(),
    jpeg_decoder_outport_pixel_offset_read(), jpeg_decoder_outport_x_read(), jpeg_decoder_outport_y_read());
  }
/*
  if(decoded_width && decoded_height)
  {
    printf("FINAL idle %ld, byte read offset %ld, write offset %ld (%d,%d)\n", jpeg_decoder_idle_status_read(),
    jpeg_decoder_reader_offset_read()*4, jpeg_decoder_outport_pixel_offset_read()*4,
    jpeg_decoder_outport_x_read(), jpeg_decoder_outport_y_read());
  }
*/

  if(decoded_width)
    *decoded_width = jpeg_decoder_outport_width_read();
  if(decoded_height)
    *decoded_height = jpeg_decoder_outport_height_read();


  jpeg_decoder_reader_enable_write(0);
  //jpeg_decoder_reader_enable_write(0);
  //printf("RESET size (%d,%d)\n", jpeg_decoder_outport_width_read(), jpeg_decoder_outport_height_read());

}

#else
#warning implement software JPEG decoder
#endif
