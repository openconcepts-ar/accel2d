# Framebuffer double buffer and vertical synchronization test
# Copyright (c) 2022-2026 Victor Suarez Rovere <suarezvictor@gmail.com>
#
# SPDX-License-Identifier: BSD-2-Clause


import litex
import math
import utime as time
from framebuf import FrameBuffer, RGB32

doublebuf = True #disable for testing tearing

video = litex.Video(0, doublebuf) #second argument enables double buffer
W, H, depth = video.width(), video.height(), video.bpp()
assert(depth == 32)

aspect = 1.0 #(4/3)/(16/9) or for 4:3 resoluton displayed in a 16:9 monitor

fbuf = [FrameBuffer(video, W, H, RGB32, video.stride())]
i = video.flip() #flip buffer to obtain addres of the 2nd buffer
fbuf += [FrameBuffer(video, W, H, RGB32, video.stride())]

def drawline(x, color):
  w = 2*math.pi*x/60
  fbuf[i].line(W//2, H//2, W//2+int(math.sin(w)*H/2*aspect), H//2-int(math.cos(w)*H/2), color)

# clear buffers
bg = 0x40FF00
fbuf[0].fill(bg);
fbuf[1].fill(bg);  

# animate
t0 = time.ticks_ms()
for x in range(300+1):
  i = video.flip()
  drawline(x-2, bg)
  drawline(x, 0x8040FF)
t = time.ticks_diff(time.ticks_ms(), t0)

#clear last line
drawline(x, bg)
i = video.flip()

fps = x*1000/t
print("FPS:", fps)
assert(fps >= 24 and fps <= 120)




