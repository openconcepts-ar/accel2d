// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "processing_api.h"

namespace processing
{

PFont createFont(const char *name, Font::fontsize_t fontsize, const char *buf, size_t bufsize)
{
	PGraphics::fontManager().load_font(name, fontsize, buf, bufsize);
	return PFont(new Font(name, fontsize));
}

} //namespace processing
