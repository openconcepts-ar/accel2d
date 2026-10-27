from umachine import SoftUART
import ustruct as struct
import utime as time

#in bridge MCU:
#define UART_TX_PIN	20 //first GPIO is TX(TP2) on bridge (so use RX here)
#define UART_RX_PIN	21 //second GPIO is RX(TP3) on bridge (so use TX here)

ser = SoftUART(tx=5, rx=4, baudrate=230400, timeout=100) #tx=GPIO5/MOSI/RTS# rx=GPIO4/MISO/CTS#

STRUCT_FORMAT = '<2B1H2B3H'
STRUCT_SIZE = struct.calcsize(STRUCT_FORMAT)
assert STRUCT_SIZE == 12;
MAGIC = 0x03 #matches TUSB_CLASS_HID

def read_data(ser, n, partial = False):
	data = bytes(0)
	while True:
		try:
			if n <= 0: return data
			r = ser.read(n)
			if not r and partial: return data
			data = data + r
			n -= len(data)
		except OSError as e:
			if e.args[0] == 11: #errno.EAGAIN
				print("*", data, len(data), "remains", n)
				if not partial: continue
			elif e.args[0] == 5: #errno.EIO
				print("?")
			else:
				print("Unknown UART error", e)
			break
	return data

def run(ser):
	_ = ser.write(b'\x00') #trigger next read
	ser.flush()

	data = read_data(ser, 1)
	if data[0] != MAGIC: #usually 0
		if data[0] != 0:
			print("UNEXPECTED DATA", data)
		return False

	data = data + read_data(ser, STRUCT_SIZE-1)

	if len(data) != STRUCT_SIZE:
		print("MISSING DATA", len(data), data)
		return False
		
	magic, evt, millis, addr, instance, vid, pid, length = struct.unpack(STRUCT_FORMAT, data)
	header = (
    	"Magic %02x "
    	"EVENT type %02x, "
    	"time %dms, "
    	"addr %02x, "
    	"instance %02x, "
    	"[%04x:%04x] "
    	"payload len %04x:"
	) % (magic, evt, millis, addr, instance, vid, pid, length)
	print("HEADER", header)
	payload = read_data(ser, length, True) if length else bytes(0)
	print("PAYLOAD", len(payload), payload)
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

