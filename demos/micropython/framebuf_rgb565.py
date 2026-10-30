# Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

RED = 0xF800
GREEN = 0x07E0
BLUE = 0x001F
WHITE = 0xFFFF

from framebuf import FrameBuffer, RGB565
import litex

video = litex.Video(0)
W = video.width()
H = video.height()
assert video.bpp() == 16
fbuf = FrameBuffer(video, W, H, RGB565, video.stride())

fbuf.fill_rect(W//4, H//4, 2*W//4, 2*H//4, BLUE)
fbuf.fill_rect(W//4, H//4, 2*2*W//12, 2*H//4, GREEN)
fbuf.fill_rect(W//4, H//4, 2*W//12, 2*H//4, RED)
fbuf.line(0, 0, W, H, WHITE)
video.flush()

