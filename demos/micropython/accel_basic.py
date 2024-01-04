# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

import litex
from framebuf import FrameBuffer, RGB32
video = litex.Video(0)
fbuf = FrameBuffer(video, video.width(), video.height(), RGB32, video.stride())
video.flush() #makes sure screen gets completely clear
fbuf.fill_rect(100, 100, 200, 200, 0x0000FF)
fbuf.fill_rect(150, 150, 200, 200, 0x00FF00)
fbuf.fill_rect(200, 200, 200, 200, 0xFF0000)

