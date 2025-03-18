// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __PROCESSING_API_H__
#define __PROCESSING_API_H__

#include "accel_canvas.h"

#include <memory> //shared_ptr
#include <string>

namespace processing
{

class Font
{
public:
	typedef float fontsize_t;

protected:
	std::string m_name;
	fontsize_t m_height;

public:
	Font(const char *name, fontsize_t height) : m_name(name), m_height(height) { }
	const char *fontname() const { return m_name.c_str(); }
	fontsize_t height() const { return m_height; }
};

typedef std::shared_ptr<Font> PFont;

//see https://processing.github.io/processing-javadocs/core/
class PGraphics : public CanvasBase
{
	typedef CanvasBase base;
	color_t m_bgColor, m_fillColor, m_strokeColor;
	coord_t m_strokeWidth;
	PFont m_currentFont;
	
	friend PFont createFont(const char *name, Font::fontsize_t fontsize, const char *buf, size_t bufsize);

	path_t m_lastpath;
	
public:
	int& width;
	int& height;
	
	PGraphics() :
		m_bgColor(0x33, 0x33, 0x33),
		m_fillColor(0x66, 0x66, 0x66, 0xFF),
		m_strokeColor(0, 0, 0, 0), //start noStroke
		m_strokeWidth(1),
		width(m_width), height(m_height)
	{
	}
	
	void background(color_channel_t r, color_channel_t g, color_channel_t b, color_channel_t a = 255) { m_bgColor = color_t(r, g, b, a); }
	void background(color_t color) { m_bgColor = color; }
	color_t background() const { return m_bgColor; }

	void clear() { m_ren.clear(m_bgColor); }
	void cleartocheckers(int sqsize = 16);

	void fill(color_channel_t r, color_channel_t g, color_channel_t b, color_channel_t a = 255) { m_fillColor = color_t(r, g, b, a); }
	void fill(color_t color) { m_fillColor = color; }
	color_t fill() const { return m_fillColor; }
	void noFill() { m_fillColor.transparent(); }

	void stroke(color_channel_t r, color_channel_t g, color_channel_t b, color_channel_t a = 255) { m_strokeColor = color_t(r, g, b, a); }
	void stroke(color_t color) { m_strokeColor = color; }
	color_t stroke() const { return m_strokeColor; }
	void noStroke() { m_strokeColor.transparent(); }
	
	//
	// Font
	//
	void textFont(PFont font)
	{
		PGraphics::fontManager().load_font(font->fontname(), font->height());
		m_currentFont = font;
	}
	
	void text(std::string str, coord_t x, coord_t y)
	{
		agg::path_storage path(fontManager().text(str.c_str(), x, y));
		
   		conv_path_t glyphs(path);
   		render_fill(glyphs, m_fillColor);
	}

	void textNoCurves(std::string str, coord_t x, coord_t y)
	{
		agg::path_storage path(fontManager().text(str.c_str(), x, y));
   		render_fill(path, m_fillColor);
	}

	//
	// Shape - 2D Primitives
	//
	void rect(coord_t x, coord_t y, coord_t w, coord_t h, coord_t r = 0)
	{
		m_lastpath.remove_all();
		agg::rounded_rect rect1(x, y, w, h, r);
		m_lastpath.concat_path(rect1);
		render_fill(rect1, m_fillColor);
	}

	void ellipse(coord_t cx, coord_t cy, coord_t rx, coord_t ry)
	{
		m_lastpath.remove_all();
		agg::ellipse el(cx, cy, rx, ry);
		//printf("ellipse %d, %d, %d, %d, color %d,%d,%d,%d(r)\n", int(cx), int(cy), int(rx), int(ry), m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.a);
		m_lastpath.concat_path(el);
		render_fill(m_lastpath, m_fillColor);
	}

	void line(coord_t x1, coord_t y1, coord_t x2, coord_t y2)
	{
		m_lastpath.remove_all();
		m_lastpath.move_to(x1, y1);
		m_lastpath.line_to(x2, y2);
#ifdef ACCEL_LINE32_REGION
		if(m_strokeWidth == 1)
		{
			m_pixf.line(x1, y1, x2-x1, y2-y1, m_strokeColor); //hardware acclerated version
			return;
		}
#endif
		render_stroke(m_lastpath, m_strokeColor, m_strokeWidth);
	}

	void point(coord_t x, coord_t y) { m_pixf.copy_hline(x, y, 1, m_strokeColor); }

	template <class T>
	void draw(T& path, coord_t dx, coord_t dy)
	{
		agg::trans_affine mtx;
		conv_path_t conv(path); //FIXME: optimize by using already converted paths
        agg::conv_transform<conv_path_t> trans_shape(conv, mtx);
		mtx.translate(dx, dy);
		render_fill(trans_shape, m_fillColor);
	}
	
	path_t& lastshape() { return m_lastpath; };
	void lastshape(coord_t dx, coord_t dy) { draw(lastshape(), dx, dy); }


	//
	// Shape - Attributes
	//
	void strokeWeight(coord_t weight) { m_strokeWidth = weight; }
};

static const PGraphics::color_t 
	RED(0xff, 0, 0, 0xff),
	GREEN(0, 0xff, 0, 0xff),
	BLUE(0, 0, 0xff, 0xff),
	YELLOW(0xff, 0xff, 0, 0xff),
	WHITE(0xff, 0xff, 0xff, 0xff),
	DARKGRAY(0x40, 0x40, 0x40, 0xff),
	GRAY(0x80, 0x80, 0x80, 0xff),
	LIGHTGRAY(0xc0, 0xc0, 0xc0, 0xff),
	BLACK(0, 0, 0, 0xff),
	SHADOW(0, 0, 0, 96),
	LIGHT(0xff, 0xff, 0xff, 96);
	
PFont createFont(const char *name, Font::fontsize_t fontsize, const char *buf = nullptr, size_t bufsize = 0);

//
//misc functions
//
static inline void println(std::string x) { printf("%s\n", x.c_str()); }

static inline PGraphics::angle_radians_t radians(PGraphics::angle_degrees_t degrees)
{
	return degrees*M_PI/PGraphics::angle_degrees_t(180.0);
}

static inline float random(float bottom, float top) { return bottom + (top-bottom)*rand()/RAND_MAX; }
static inline float random(float top) { return random(0, top); }

} //namespace processing

#endif // __PROCESSING_API_H__
