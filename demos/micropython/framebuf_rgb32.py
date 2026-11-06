# Copyright (c) 2023-2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

WHITE = 0xFFFFFF

from framebuf import FrameBuffer, RGB32
import litex

video = litex.Video(0)
W = video.width()
H = video.height()
assert video.bpp() == 32
fbuf = FrameBuffer(video, W, H, RGB32, video.stride())

band_h = H // 4

for x in range(W):
    v = x & 255
    fbuf.vline(x, 0 * band_h, band_h, v << 16)  # red gradient
    fbuf.vline(x, 1 * band_h, band_h, v << 8)   # green gradient
    fbuf.vline(x, 2 * band_h, band_h, v)        # blue gradient
    fbuf.vline(x, 3 * band_h, band_h, v * 0x010101) # white gradient

fbuf.line(0, 0, W, H, WHITE)  # optional: keep the diagonal reference line
video.flush()
