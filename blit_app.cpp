#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memset & memcpy

#include "misc.h"
#include "accel_cores.h"
#include "graphics.h"


enum blit_mode
{
  BLIT_SOLID = 0,
  BLIT_SOLID_ALPHA = 1,
  BLIT_COPY = 2,
  BLIT_TINT = 3,
  BLIT_MODE_COUNT = BLIT_TINT+1
};

static accel_line32a_layout_t *regs;
static void blit(uint32_t *dstbase, size_t dstpitch, const uint32_t *srcbase, size_t srcpitch, unsigned w, unsigned h, uint32_t srcmult, uint32_t dstadd)
{
	while(h--)
	{
		accel_linea(regs, w, 0, dstadd, srcmult,
		  (uintptr_t)dstbase, dstpitch,
		  (uintptr_t)srcbase, srcpitch,
		  1, 1
		);

		dstbase += dstpitch;
		srcbase += srcpitch;
	}

}

static __attribute__((aligned(16)))
uint32_t bitmap[FRAME_HEIGHT][FRAME_WIDTH];

static unsigned draw(blit_mode mode, unsigned bitmap_w, unsigned bitmap_h)
{
	for(;;)
	{
		uintptr_t dst = VIDEO_FRAMEBUFFER_BASE;
		const uint32_t *src = bitmap[0];
		
		unsigned x0 = rand() % FRAME_WIDTH;
		unsigned y0 = rand() % FRAME_HEIGHT;
		unsigned w = (rand() % (bitmap_w/2+1)) + bitmap_w/2;
		unsigned h = (rand() % (bitmap_h/2+1)) + bitmap_h/2;


		uint32_t tint = rand();
		uint8_t tint_r = tint;
		uint8_t tint_g = tint >> 8;
		uint8_t tint_b = tint >> 16;
		uint8_t tint_a = tint >> 24;
		
		uint8_t fg_r = rand() % (256 - tint_r);
		uint8_t fg_g = rand() % (256 - tint_g);
		uint8_t fg_b = rand() % (256 - tint_b);
		uint8_t fg_a = 255-tint_a;
		uint32_t fg = rgba2raw(fg_r, fg_g, fg_b, fg_a);

		switch(mode)
		{
		  case BLIT_COPY:
			fg = 0;
			tint = 0xFFFFFFFF;
			if(!regs) //make sure 128-bit aligned (for testing/optimization, not required)
			{
				x0 &= ~3;
				y0 &= ~1;
			}
			break;
		  case BLIT_SOLID:
			tint = 0;
			break;
		  case BLIT_SOLID_ALPHA:
			tint &= rgba2raw(tint_a, tint_a, tint_a, tint_a); //premultiplied
			break;
		  default:
		    break;
		}

		if(x0 + w > FRAME_WIDTH)
		  w = FRAME_WIDTH - x0;
		if(y0 + h > FRAME_HEIGHT)
		  h = FRAME_HEIGHT - y0;
		  
		dst += x0*4 + y0 * FRAME_PITCH;
		if(mode == BLIT_SOLID || mode == BLIT_SOLID_ALPHA)
			src = (uint32_t*) dst;

		blit((uint32_t *) dst, FRAME_PITCH/4, src, sizeof(bitmap[0])/4, w, h, tint, fg);
		
		return w*h;
	}
}

extern const unsigned char _binary_bmpimage_start[];
extern const unsigned char _binary_bmpimage_end[];


extern "C" void graphics_app(void)
{
	printf("blit_app, buffer %p, resolution %dx%d\n", (void *) VIDEO_FRAMEBUFFER_BASE, FRAME_WIDTH, FRAME_HEIGHT);
    printf("Image data at: %p\n", _binary_bmpimage_start);
    printf("Image size: %u bytes, storage_width %d\n", _binary_bmpimage_end-_binary_bmpimage_start, sizeof(bitmap[0])/4);

	unsigned bitmap_w = FRAME_WIDTH, bitmap_h = FRAME_HEIGHT;
    accel_bmp_decode(_binary_bmpimage_start, _binary_bmpimage_end-_binary_bmpimage_start, bitmap, sizeof(bitmap[0]), &bitmap_w, &bitmap_h, 1, 1);
    printf("BMP size %ux%u, pitch %d\n", bitmap_w, bitmap_h, sizeof(bitmap[0]));

	int frame = 0;
	for(;;)
	{
		uint64_t t0 = highres_ticks();
		int seconds = int(t0/highres_ticks_freq());
		int t = seconds / 5;
		blit_mode mode = (blit_mode) ((t>>1) % BLIT_MODE_COUNT);
		bool soft = t & 1;
		regs = soft ? NULL : accel_line32a_regs;
		size_t pixel_count = draw(mode, bitmap_w, bitmap_h);
		int64_t dt = highres_ticks() - t0;
		
		printf("frame %d, t %d, FPS %d (resolution %dx%d) ticks %ld%s\n",
			++frame, seconds, pixel_count*int(highres_ticks_freq()/dt)/(FRAME_WIDTH*FRAME_HEIGHT),
			FRAME_WIDTH, FRAME_HEIGHT, long(dt),
			soft ? " (FORCE SOFTWARE)" : "");

#ifdef DISABLE_HARDWARE_ACCEL 
	void wait_vsync(void);
	wait_vsync();
#endif
	}
}

