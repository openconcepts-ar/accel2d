from umachine import SoftUART
import ustruct as struct
import utime as time

"""
HID bridge test in micropython. Connection:

GPIO20 is TX on bridge, so use RX here (GPIO4 on FPGA board)
GPIO21 is RX on bridge, so use TX here (GPIO5 on FPGA board)

Typical response for a touch digitizer is:
x, y, id, tip, time 907 405 0 1 25683
x, y, id, tip, time 1153 362 1 1 25683
x, y, id, tip, time 907 405 0 0 25778
x, y, id, tip, time 1153 362 1 0 25778

"""
ser = SoftUART(baudrate=230400, timeout=100)

STRUCT_FORMAT = '<2B1H2B3H'
STRUCT_SIZE = struct.calcsize(STRUCT_FORMAT)
assert STRUCT_SIZE == 12;
MAGIC = 0x03 #matches TUSB_CLASS_HID

def read_data(ser, n):
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

def run(ser):
	_ = ser.write(b'\x00') #trigger next read
	ser.flush()

	data = read_data(ser, 1)
	if data[0] != MAGIC: #usually 0
		return False

	data = data + read_data(ser, STRUCT_SIZE-1)

	if len(data) != STRUCT_SIZE:
		print("MISSING DATA", len(data), data)
		return False
		
	magic, evt, millis, addr, instance, vid, pid, length = struct.unpack(STRUCT_FORMAT, data)
	payload = read_data(ser, length)

	if evt == 2 and addr == 1 and instance == 0 and vid == 0x2a94 and pid == 0x5009 and length == 64:
		#touch info
		scantime, count = struct.unpack_from('<HB', payload, 61) #offset to scan data and count
		assert(count <= 10)
		for i in range(count):
			flags, touchid, x, y = struct.unpack_from('<BBHH', payload, 1 + i * 6)		
			print("x, y, id, tip, time", x, y, touchid, flags & 1, scantime)
	else:
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

	return True

while True:
	if run(ser): continue
	time.sleep(1/60) #simulate a MCU processing delay

"""
#basic communication test
while True:
	_ = ser.write(b'\x00')
	ser.flush()
	try:
		data = ser.read(7) #expects "Hello\r\n"
		print(data.decode(), end="")
	except OSError as e:
		if e.args[0] == 11: #errno.EAGAIN
			print("*")
		elif e.args[0] == 5: #errno.EIO
			print("?")
		else:
			print("Unknown UART error", e)
			break
"""

