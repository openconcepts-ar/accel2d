#include <stdint.h>
#include <time.h>
#include <stdio.h>

#include "misc.h"
#include "graphics.h"

#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_SOFTWARE_FONT

#include "nuklear.h"

#define NK_RAWFB_IMPLEMENTATION
#define NK_RAWFB_ACCEL //enable hardware accelerated primitives
static void nk_accel_clear(const struct rawfb_image *fb, uint32_t col);
static void nk_accel_line(const struct rawfb_image *fb, int x0, int y0, int x1, int y1, uint32_t col);
static void nk_accel_image(const struct rawfb_image *dst,
    const struct rawfb_image *src, struct nk_rect dst_rect,
    struct nk_rect src_rect, struct nk_rect dst_scissors,
    uint32_t fg_col, uint32_t bg_col);

#include "demo/rawfb/nuklear_rawfb.h"
static rawfb_context *rawfb = NULL;

#include "demo/common/calculator.c" //selected demo

static void draw()
{
    nk_input_begin(&rawfb->ctx);
    //TODO: handle events
    nk_input_end(&rawfb->ctx);

    calculator(&rawfb->ctx);
    nk_rawfb_render(rawfb, nk_rgb(100,30,30), true);
    
    //show default font atlas
    nk_accel_image(&rawfb->fb, &rawfb->font_tex,
    	(struct nk_rect){0, rawfb->fb.h/2, rawfb->font_tex.w, rawfb->font_tex.h},
    	(struct nk_rect){0, 0, rawfb->font_tex.w, rawfb->font_tex.h},
    	rawfb->scissors, 0xFF00FFFF, 0x000000FF);
}

extern "C" void wait_vsync(void);

extern "C" void graphics_app(void)
{
    struct rawfb_pl pl;
    pl.bytesPerPixel = 4;
    pl.ashift = 24;
    pl.rshift = 16;
    pl.gshift = 8;
    pl.bshift = 0;
    pl.aloss = 0;
    pl.rloss = 0;
    pl.gloss = 0;
    pl.bloss = 0;
        
	printf("Nuklear demo, resolution %dx%d, fb %p\n", FRAME_WIDTH, FRAME_HEIGHT, (void*) VIDEO_FRAMEBUFFER_BASE);
	static uint32_t tex[512][64] __attribute__((aligned(16)));
    rawfb = nk_rawfb_init((void*)VIDEO_FRAMEBUFFER_BASE, &tex[0][0], FRAME_WIDTH, FRAME_HEIGHT, FRAME_PITCH, pl);


	uint64_t t0 = highres_ticks();
	int frame = 0;
	for(;;)
	{
		draw();
		int64_t dt = highres_ticks() - t0;
		//printf("frame %d, t %d, FPS %d ticks %ld\n",
		//	frame, int(t0/highres_ticks_freq()), int(highres_ticks_freq()/dt), long(dt));
		t0 += dt;

#ifdef DISABLE_HARDWARE_ACCEL
		wait_vsync();
#endif
	}
}

/////////////////////////////
//accelerators implementation
/////////////////////////////
#include "accel_cores.h"

static void blit(uint32_t *dstbase, size_t dstpitch, const uint32_t *srcbase, size_t srcpitch, unsigned w, unsigned h, uint32_t srcmult, uint32_t dstadd)
{
	while(h--)
	{
		accel_linea(accel_line32a_regs, w, 0, dstadd, srcmult,
		  (uintptr_t)dstbase, dstpitch,
		  (uintptr_t)srcbase, srcpitch,
		  1, 1
		);
		dstbase += dstpitch;
		srcbase += srcpitch;
	}
}

static void nk_accel_clear(const struct rawfb_image *fb, uint32_t col)
{
	unsigned pitch = fb->pitch;
	blit((uint32_t *) fb->pixels, pitch/4, (uint32_t *) fb->pixels, pitch/4, fb->w, fb->h, 0, col);
}

// This function is called the most, the caller has to make sure it does no exceed bounds
void nk_accel_line(const struct rawfb_image *fb, int x0, int y0, int x1, int y1, uint32_t col)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(dy == 0)
		dx += dx >= 0 ? 1 : -1; //draw last horizontal pixel
	else
	{
	  //TODO: draw last point
	}
	
	uintptr_t dst = (uintptr_t) fb->pixels;
	unsigned pitch = fb->pitch;
	dst += x0*4 + y0 * pitch;

	accel_linea(accel_line32a_regs, dx, dy, col, 0,
	  dst, pitch/4,
	  dst, pitch/4,
	  1, 1
	);
}

void nk_accel_image(const struct rawfb_image *dst,
    const struct rawfb_image *src, struct nk_rect dst_rect,
    struct nk_rect src_rect, struct nk_rect dst_scissors,
    uint32_t fg_col, uint32_t bg_col)
{
	assert(dst);
	assert(src);

	int x0 = dst_rect.x;
	int y0 = dst_rect.y;
	int w = dst_rect.w;
	int h = dst_rect.h;
	
	//printf("x0 %d, y0 %d, w %d, h %d\n", x0, y0, w, h);

	uintptr_t fb = (uintptr_t) dst->pixels;
	fb += x0*4 + y0 * dst->pitch;

	uintptr_t data = (uintptr_t) src->pixels;
	data += src_rect.x*4 + src_rect.y * src->pitch;

	blit((uint32_t *) fb, dst->pitch/4, (uint32_t *) data, src->pitch/4, w, h, fg_col, bg_col);
}

