#include <stdio.h>
#include "misc.h"
#include "accel_cores.h"
#include "graphics.h"

extern "C" void wait_vsync(void);

void draw()
{
	static uint8_t color = 0;
	for(int y = 0; y < FRAME_HEIGHT; ++y)
	{
		//selected accelerator
		accel_line(accel_line32_regs, 0, y, FRAME_WIDTH, y, color << 8);
	}
	++color;
#ifdef DISABLE_HARDWARE_ACCEL
	wait_vsync();
#endif
}

extern "C" void graphics_app(void)
{
	int frame = 0;
	uint64_t t0 = highres_ticks();
	for(;;)
	{
		draw();
		int64_t dt = highres_ticks() - t0;
		printf("frame %d, t %d, FPS %d (resolution %dx%d) ticks %ld, clocks per pixel %d\n",
			++frame, int(t0/highres_ticks_freq()), int(highres_ticks_freq()/dt),
			FRAME_WIDTH, FRAME_HEIGHT, long(dt), int(dt/(FRAME_WIDTH*FRAME_HEIGHT)));

		t0 = highres_ticks();
	}
}

