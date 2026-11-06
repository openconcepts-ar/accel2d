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

band_h = H // 4

for x in range(W):
    r = (x//2 & 0x1F) << 11
    g = (x & 0x3F) << 5
    b = x//2 & 0x1F
    fbuf.vline(x, 0 * band_h, band_h, r)  # red gradient
    fbuf.vline(x, 1 * band_h, band_h, g)  # green gradient
    fbuf.vline(x, 2 * band_h, band_h, b)  # blue gradient
    fbuf.vline(x, 3 * band_h, band_h, r | g | b) # white gradient

fbuf.line(0, 0, H, H, WHITE)  # optional: keep the diagonal reference line
video.flush()
