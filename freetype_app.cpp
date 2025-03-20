// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#include "misc.h"
#include "graphics.h"
#include "accel_cores.h"

#include <ft2build.h>
//#include FT_FREETYPE_H
//#include FT_OUTLINE_H

static int y0 = 3*FRAME_HEIGHT/4, x0 = FRAME_HEIGHT/2;
static uint8_t color = 192;

void span_callback(int y, int count, const FT_Span* spans, void* user)
{
    for (int i = 0; i < count; ++i)
    {
		int x = spans[i].x, len = spans[i].len;
		if(!len || spans[i].coverage < 128)
		  continue;

		accel_line(accel_line32_regs, x0+x, y0-y, x0+x+len, y0-y, color | 0xFF000000);
	}
}

#include "DejaVuSansMono.ttf.c" //inline font data

static FT_Library library;
static FT_Face face;
static FT_Error error;
static FT_UInt glyph_index;
static FT_Raster_Params raster_params;

void setup()
{
    // Initialize the FreeType library
    error = FT_Init_FreeType(&library);
    if (error) {
        printf("Could not initialize FreeType library\n");
        return;
    }

    // Load a font face
#if 0
    error = FT_New_Face(library, "DejaVuSansMono.ttf", 0, &face);
#else
    error = FT_New_Memory_Face(library, (const FT_Byte*) DejaVuSansMono_ttf, DejaVuSansMono_ttf_len, 0, &face);
#endif

    if (error == FT_Err_Unknown_File_Format) {
        printf("Unsupported font format\n");
        FT_Done_FreeType(library);
        return;
    } else if (error) {
        printf("Could not open font file\n");
        FT_Done_FreeType(library);
        return;
    }
    
    // Set the character size
    error = FT_Set_Char_Size(face, 0, 32 * 64 * 64, 300, 300);
    if (error) {
        printf("Could not set character size\n");
        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return;
    }

    glyph_index = FT_Get_Char_Index(face, 'g'); // Load glyph
    error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
    if (error) {
        printf("Could not load glyph\n");
        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return;
    }

    memset(&raster_params, 0, sizeof(raster_params));
    raster_params.flags = FT_RASTER_FLAG_DIRECT | FT_RASTER_FLAG_AA | FT_RASTER_FLAG_CLIP;
    raster_params.gray_spans = span_callback;
    raster_params.clip_box.xMin = -x0+10;
    raster_params.clip_box.xMax = raster_params.clip_box.xMin + FRAME_WIDTH - 20;
    raster_params.clip_box.yMin = -((FRAME_HEIGHT-y0)-10);
    raster_params.clip_box.yMax = raster_params.clip_box.yMin + FRAME_HEIGHT - 20;
}

void draw()
{
    FT_Outline* src_outline = &face->glyph->outline;
    FT_Outline dst_outline;

    error = FT_Outline_New(library, src_outline->n_points, src_outline->n_contours, &dst_outline);
    error = FT_Outline_Copy(src_outline, &dst_outline);
    
    // Apply a transformation matrix to the outline
	static FT_Matrix matrix = 
	{
        .xx = 0x1000,  // 0.1 in 16.16 fixed-point
        .xy = 0x0000,  // 0.0
        .yx = 0x0000,  // 0.0
        .yy = 0x1000,  // 0.1 
    };

    //update transform matrix and apply to outline
    matrix.xx += 8;
    matrix.yy += 8;
    FT_Outline_Transform(&dst_outline, &matrix);    

    // Render the glyph into spans
    error = FT_Outline_Render(library, &dst_outline, &raster_params);
    if (error) {
        printf("Could not render glyph\n");
        return;
    }
    
    FT_Outline_Done(library, &dst_outline); //only frees memory if owner set (not set with FT_Outline_Copy)
}

extern "C" void graphics_app()
{
    memset((void*)VIDEO_FRAMEBUFFER_BASE, 0x40, FRAME_PITCH*FRAME_HEIGHT); //clear buffer

	setup();

	int frame = 0;
	uint64_t t0 = highres_ticks();
	for(;;)
	{
		--color;
		draw();
		int64_t dt = highres_ticks() - t0;
		printf("frame %d, t %d, FPS %d ticks %ld\n",
			frame, int(t0/highres_ticks_freq()), int(highres_ticks_freq()/dt), long(dt));

		t0 = highres_ticks();
		++frame;

		if(color == 255)
			break;
		
	}

    // Cleanup
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

//dependencies
extern "C"
{
//#define FT_DEBUG_LEVEL_TRACE
//#define FT_DEBUG_LEVEL_ERROR
#include "FreeTypeAmalgam.c"
}

