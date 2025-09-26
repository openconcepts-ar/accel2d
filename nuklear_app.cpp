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
#include "demo/rawfb/nuklear_rawfb.h"
static struct rawfb_context *rawfb = NULL;

#include "demo/common/calculator.c" //selected demo

static void draw()
{
        nk_input_begin(&rawfb->ctx);
        //TODO: handle events
        nk_input_end(&rawfb->ctx);

        calculator(&rawfb->ctx);
        nk_rawfb_render(rawfb, nk_rgb(100,30,30), true);
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
        
    static unsigned char tex_scratch[512 * 512];

    rawfb = nk_rawfb_init((void*)VIDEO_FRAMEBUFFER_BASE, tex_scratch, FRAME_WIDTH, FRAME_HEIGHT, FRAME_PITCH, pl);

	printf("Nuklear demo, resolution %dx%d, fb %p\n", FRAME_WIDTH, FRAME_HEIGHT, rawfb->fb.pixels);

	uint64_t t0 = highres_ticks();
	int frame = 0;
	for(;;)
	{
		draw();
		int64_t dt = highres_ticks() - t0;
		printf("frame %d, t %d, FPS %d ticks %ld\n",
			frame, int(t0/highres_ticks_freq()), int(highres_ticks_freq()/dt), long(dt));
		t0 += dt;

#ifdef DISABLE_HARDWARE_ACCEL
		wait_vsync();
#endif
	}
}
