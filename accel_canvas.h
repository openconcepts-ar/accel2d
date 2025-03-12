// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only
// line clipping algorithm Copyright (c) 2017 Sagar Ganiga MIT License

#ifndef __ACCEL_CANVAS_H__
#define __ACCEL_CANVAS_H__

#include <stdlib.h> //avoids including a incorrect one by <string> in font_cache.h
#include <assert.h>

#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "misc.h"
#include "graphics.h"
#include "accel_cores.h" //defines ACCEL_LINE32_REGION & others

#include "agg_pixfmt_rgba.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_renderer_base.h"
#include "agg_renderer_scanline.h"
#include "agg_rounded_rect.h"
#include "agg_ellipse.h"
#include "agg_scanline_p.h"
#include "agg_scanline_u.h"
#include "agg_path_storage.h"
#include "agg_conv_transform.h"
#include "agg_conv_stroke.h"

#include "agg_font_cache_manager.h"
#include "agg_font_freetype.h"

namespace agg
{

enum CohenBorder
{
	INSIDE = 0,
	LEFT = 1,
	RIGHT = 2,
	BOTTOM = 4,
	TOP = 8
};

// Compute the region code for a point (x, y) based on the clipping window
int computeRegionCode(int x, int y, int xmin, int xmax, int ymin, int ymax)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax) 
        code |= TOP;

    return code;
}

//line clipping algorithm
// https://github.com/SagarGaniga/computer-graphics/blob/master/Cohen%20Sutherland/CohenSutherland.cpp
bool cohenSutherlandClip(int xmin, int ymin, int xmax, int ymax, 
                         int& x1, int& y1, int& x2, int& y2)
{
    int code1, code2;
    bool accept = false;

    // Compute the region codes for the two endpoints
    code1 = computeRegionCode(x1, y1, xmin, xmax, ymin, ymax);
    code2 = computeRegionCode(x2, y2, xmin, xmax, ymin, ymax);

    while (true)
    {
        if ((code1 == INSIDE) && (code2 == INSIDE))
        {
            // Both points are inside, accept the line
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // Logical AND is non-zero, both points are outside, reject the line
            break;
        }
        else
        {
            // Line needs clipping
            int codeOut;
            float x, y;

            // Choose one of the points that is outside
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Find the intersection point
            if (codeOut & TOP)
            {  // point is above the clip window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {  // point is below the clip window
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {  // point is to the right of the clip window
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeOut & LEFT)
            {  // point is to the left of the clip window
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace the outside point with the intersection point
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1, xmin, xmax, ymin, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2, xmin, xmax, ymin, ymax);
            }
        }
    }
    return accept;
}

#ifdef ACCEL_LINE32_REGION
struct display_pixel_format : pixfmt_rgba32
{
	typedef pixfmt_rgba32 base;

    using base::base;

	AGG_INLINE void line(int x, int y, int dx, int dy, const color_type& c)
	{
		uint32_t color = rgba2raw(c.r, c.g, c.b, c.a);
		int x0 = x, x1 = x + dx, y0 = y, y1 = y+dy;
		if(cohenSutherlandClip(0, 0, FRAME_WIDTH, FRAME_HEIGHT, x0, y0, x1, y1))
			accel_line(accel_line32_regs, x0, y0, x1, y1, color);
	}
	
    //this is used by the renderer_base's clear function
    AGG_INLINE void copy_hline(int x, int y, unsigned len, const color_type& c)
    {
		accel_line(accel_line32_regs, x, y, x+len, y, rgba2raw(c.r, c.g, c.b, c.a));
    }

	//used for the solid fill portions
	AGG_INLINE void blend_hline(int x, int y, unsigned len,  const color_type& c, int8u cover)
	{
		if(cover > 127)
			copy_hline(x, y, len, c);
	}


	void attach(rbuf_type& rb) { m_rbuf2 = &rb; base::attach(rb); }
protected:
	rbuf_type* m_rbuf2; //FIXME: duplicated!!
};

#else
#error ACCEL_LINE32_REGION not defined
typedef pixfmt_rgba32 display_pixel_format; //pure software implementation
#endif

} //namespace agg



class FontManager
{
	typedef agg::font_engine_freetype_int32 FontEngine;
	typedef agg::font_cache_manager<FontEngine> FontCacheManager;

	FontEngine m_fontEngine;
	FontCacheManager m_fontCacheManager;

	double m_fontHeight;

public:
	FontManager() : m_fontEngine(), m_fontCacheManager(m_fontEngine) { m_fontEngine.flip_y(true); }

	void load_font(const char *name, double height, const void *buf = nullptr, size_t bufsize = 0)
	{
		m_fontEngine.load_font(name, 0, agg::glyph_ren_outline, (const char *) buf, bufsize);
		m_fontEngine.height(height);
		m_fontHeight = height;
	}

	agg::path_storage text(const char* str, double x, double y)
	{
		double start_x = x;
		double start_y = y;

		agg::trans_affine mtx; //FIXME: needed?
		agg::conv_transform<FontCacheManager::path_adaptor_type> tr(m_fontCacheManager.path_adaptor(), mtx);
	    agg::path_storage path;

		int i;
		for (i = 0; str[i]; i++)
		{
			const agg::glyph_cache* glyph = m_fontCacheManager.glyph(str[i]);
			if(glyph)
			{
				if(i)
					m_fontCacheManager.add_kerning(&start_x, &start_y);

				m_fontCacheManager.init_embedded_adaptors(glyph, start_x, start_y);
				path.concat_path(tr, 0);

				start_x += glyph->advance_x;
				start_y += glyph->advance_y;
			}
		}
		
		return path;
	}
};


class CanvasBase
{
	static FontManager *m_fontManager;

public:
	typedef agg::rgba8 color_t;
	typedef color_t::value_type color_channel_t;
	typedef agg::path_storage path_t;
	typedef float coord_t;
	typedef float angle_radians_t, angle_degrees_t;

protected:
    typedef agg::renderer_base<agg::display_pixel_format> renderer_base_t;
	typedef agg::rendering_buffer rendering_buffer_t;
	typedef agg::conv_curve<path_t> conv_path_t;

	renderer_base_t m_ren;
	agg::rendering_buffer m_renderbuf;
	agg::display_pixel_format m_pixf;
	agg::rasterizer_scanline_aa<> m_ras;
	agg::scanline_bin m_scanline;
	agg::renderer_scanline_bin_solid<renderer_base_t> m_renderer;

	int m_width, m_height, m_pitch;

	static FontManager& fontManager()
	{
		if(!m_fontManager)
			m_fontManager = new FontManager; //this cannot be initialized at startup
		return *m_fontManager;
	}
	
public:
	CanvasBase(int width = FRAME_WIDTH, int height = FRAME_HEIGHT, size_t pitch = FRAME_PITCH)
	: m_width(width), m_height(height), m_pitch(pitch), m_renderer(m_ren)
	{
		m_renderbuf.attach((unsigned char *) VIDEO_FRAMEBUFFER_BASE, width, height, pitch);
		m_pixf.attach(m_renderbuf);
		m_ren.attach(m_pixf);
	}
protected:
	template <class T>
	void render_fill(T& v, color_t color)
	{
		
		m_ras.add_path(v);
    	m_renderer.color(color);
    	agg::render_scanlines(m_ras, m_scanline, m_renderer);
		m_ras.reset();
	}

	typedef agg::conv_stroke<conv_path_t> conv_stroke_t;
	template <class T>
	void render_stroke(T& v, color_t color, coord_t width)
	{
		if (width > 0)
        {
			conv_path_t conv(v); //FIXME: is conversion allways needed?
			conv_stroke_t stroke_curve(conv);
			stroke_curve.width(width);
			render_fill(stroke_curve, color);
        }
    }
};

#endif //__ACCEL_CANVAS_H__
