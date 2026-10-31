# Copyright (C) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

import ustruct as struct
import utime as time
import litex
from umachine import SoftUART
from framebuf import FrameBuffer, RGB32

ser = SoftUART(baudrate=230400, timeout=10)

video = litex.Video(0)
W, H = video.width(), video.height()
fbuf = FrameBuffer(video, W, H, RGB32, video.stride())

STRUCT_FORMAT = '<2B1H2B3H'
STRUCT_SIZE = struct.calcsize(STRUCT_FORMAT)
assert STRUCT_SIZE == 12;
MAGIC = 0x03 #matches TUSB_CLASS_HID

def read_data(n):
	data = bytes(0)
	while True:
		try:
			if n <= 0: return data
			r = ser.read(n)
			data = data + r
			n -= len(data)
		except OSError as e:
			if e.args[0] == 11: #errno.EAGAIN
				continue
			elif e.args[0] == 5: #errno.EIO
				print("UART EIO error")
			else:
				print("Unknown UART error", e)
			break
	return data

def run():
	_ = ser.write(b'\x00') #trigger next read
	ser.flush()

	data = read_data(1)
	if data[0] != MAGIC: #usually 0
		return False

	data = data + read_data(STRUCT_SIZE-1)

	if len(data) != STRUCT_SIZE:
		print("MISSING DATA", len(data), data)
		return False
		
	magic, evt, millis, addr, instance, vid, pid, length = struct.unpack(STRUCT_FORMAT, data)
	payload = read_data(length)

	if evt != 2:
		header = (
			"Magic %02x "
			"EVENT type %02x, "
			"time %dms, "
			"addr %02x, "
			"instance %02x, "
			"[%04x:%04x] "
			"payload len %04x:"
		) % (magic, evt, millis, addr, instance, vid, pid, length)
		print("Receved a HID packet", header, payload)

	if evt == 0:
		print("DEVICE ATTACHED", addr, instance)
	elif evt == 1:
		print("DEVICE DETACCHED", addr, instance)
	elif evt == 2 and addr == 1 and instance == 0 and vid == 0x2a94 and pid == 0x5009 and length == 64:
		scantime, count = struct.unpack_from('<HB', payload, 61) #offset to scan data and count
		assert(count <= 10)
		touch = {}
		for i in range(count):
			flags, touchid, x, y = struct.unpack_from('<BBHH', payload, 1 + i * 6)
			#print("x, y, id, tip, time", x, y, touchid, flags & 1, scantime)
			x = x * W // 1920 #adjust default scale
			y = y * H // 1080
			touch[touchid] = (x, y, flags & 1, scantime)
		if count >= 2: #draw a line between the two fingers
			it = iter(touch.values())
			x0, y0, _, _ = next(it)
			x1, y1, _, _ = next(it)
			red = abs(255 - x0 - x1) & 0xFF
			blue = abs(255 - y0 - y1) & 0xFF
			green = red ^ blue
			fbuf.line(x0, y0, x1, y1, red | (green << 8) | (blue << 16))
	
	return True

bg = 0x40FF00
fbuf.fill(bg) # clears buffer
count = 0
while count < 1000:
	if run():
		count += 1

