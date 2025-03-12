// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "accel_canvas.h"

FontManager *CanvasBase::m_fontManager = nullptr;

// AAG dependencies
#include "../src/agg_arc.cpp"
#include "../src/agg_arrowhead.cpp"
#include "../src/agg_bezier_arc.cpp"
#include "../src/agg_bspline.cpp"
#include "../src/agg_curves.cpp"
#include "../src/agg_gsv_text.cpp"
#include "../src/agg_image_filters.cpp"
#include "../src/agg_line_aa_basics.cpp"
#include "../src/agg_line_profile_aa.cpp"
#include "../src/agg_rounded_rect.cpp"
#include "../src/agg_sqrt_tables.cpp"
#include "../src/agg_trans_affine.cpp"
#include "../src/agg_trans_warp_magnifier.cpp"
#include "../src/agg_trans_single_path.cpp"
#include "../src/agg_trans_double_path.cpp"
#include "../src/agg_vcgen_stroke.cpp"

//font dependencies
#include "../src/agg_font_freetype.cpp"
extern "C"
{
//#define FT_DEBUG_LEVEL_TRACE
//#define FT_DEBUG_LEVEL_ERROR
#include "FreeTypeAmalgam.c"
}

