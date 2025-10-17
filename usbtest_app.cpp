#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "misc.h"
#include "accel_cores.h"
#include "graphics.h"

#ifndef DISABLE_HARDWARE_ACCEL 

#include <irq.h>

#ifdef __GNUC__
#define USB_FAST_DATA __attribute__ ((section (".fast_data")))
#define USB_FAST_CODE __attribute__ ((section (".fast_text")))
#define USB_WEAK __attribute__((weak)) 
#define _packed  __attribute__((packed))
#else
#error You need a compiler that supports assigning code and data to specific linker sections, and weak functions
#endif

#include <litesdk_timer.h>
#include <litesdk_gpio.h>

//timer access
static inline uint32_t cpu_hal_get_cycle_count(void)
{
	timer0_uptime_latch_write(1);
	return csr_read_simple(CSR_TIMER0_UPTIME_CYCLES_ADDR+4);
}
#define F_CPU CONFIG_CLOCK_FREQUENCY
#define hal_get_cpu_mhz() (F_CPU/1000000)
#define TIMER_SCALE 1000000

typedef void (*timer_isr_t)(void);
timer_isr_t timer_handler = NULL;

extern "C" void timer0_isr(void)
{
	timer0_ev_pending_write(timer0_ev_pending_read());
	if(timer_handler)
		timer_handler();
}

static void litex_timer_setup(uint32_t usec, timer_isr_t handler)
{
	timer_handler = handler;
	litetimer_t *tim = litetimer_instance(0);
	 
	litetimer_set_periodic_cycles(tim, litetimer_us_to_cycles(tim, usec));
	irq_setmask(irq_getmask() | (1 << TIMER0_INTERRUPT));
	timer0_ev_pending_write(timer0_ev_pending_read());
	timer0_ev_enable_write(1);
	litetimer_start(tim);
}


//GPIO access
#define USBHOST_GPIO litegpio0 //required by LiteX implementation
#define USBHOST_ENABLED

#define GPIO_MODE_OUTPUT true
#define GPIO_MODE_INPUT false

#define hal_gpio_pad_select_gpio(pin)
#define hal_gpio_set_direction(pin, output) if(output) litegpio_mode_output(USBHOST_GPIO, pin); else litegpio_mode_input(USBHOST_GPIO, pin)
#define hal_gpio_set_level(pin, level) litegpio_write(USBHOST_GPIO, pin, level)
#define hal_gpio_read(pin) litegpio_read(USBHOST_GPIO, pin)
#define hal_gpio_pulldown_en(pin)

#define hal_enable_irq() irq_setie(1)
#define hal_disable_irq() irq_setie(0)

#define hal_set_differential_gpio_value(dp, dm,v) hal_gpio_set_pins_value(hal_pin2value(dp, dm, v))
#define hal_gpio_set_pins_value(v) USBHOST_GPIO->OUT = (v)
#define hal_pin2value(dp, dm, v) ((v & 1) << (dm)) | ((v == 0) << (dp)) //| (1 << BLINK_GPIO)

#define SET_I(dp, dm)  USBHOST_GPIO->OE &= ~((1 << dp) | (1 << dm))
#define SET_O(dp, dm)  USBHOST_GPIO->OE |= (1 << dp) | (1 << dm)
#define SE_J USBHOST_GPIO->OUT = 1 << DP_PIN //clear / set
#define SE_0 USBHOST_GPIO->OUT = 0 //clear / clear
#define READ_BOTH_PINS (((USBHOST_GPIO->IN & RD_MASK)<<8)>>RD_SHIFT)



//USB messages queue management
typedef struct
{
  uint8_t src;
  uint8_t len;
  uint8_t data[0x8];
} USBMessage;


struct hal_fifo;
typedef hal_fifo *hal_queue_handle_t;

hal_queue_handle_t hal_queue_create(size_t n, size_t sz, void *buffer);
void hal_queue_send(hal_queue_handle_t, USBMessage *);
bool hal_queue_receive(hal_queue_handle_t, USBMessage *);

extern hal_queue_handle_t usb_msg_queue;
void usbh_pins_init(int DP_P0, int DM_P0, int DP_P1, int DM_P1, int queue_size);
typedef int hal_gpio_num_t;

#include "usb_host/usb_test/main/usb_host.h"

void usbh_on_detect( uint8_t usbNum, void * dev )
{
	sDevDesc *device = (sDevDesc*)dev;
	printf("usbh_on_detect: New device detected on USB#%d\n", usbNum);
	printf("desc.bcdUSB             = 0x%04x\n", device->bcdUSB);
	printf("desc.bDeviceClass       = 0x%02x\n", device->bDeviceClass);
	printf("desc.bDeviceSubClass    = 0x%02x\n", device->bDeviceSubClass);
	printf("desc.bDeviceProtocol    = 0x%02x\n", device->bDeviceProtocol);
	printf("desc.bMaxPacketSize0    = 0x%02x\n", device->bMaxPacketSize0);
	printf("desc.idVendor           = 0x%04x\n", device->idVendor);
	printf("desc.idProduct          = 0x%04x\n", device->idProduct);
	printf("desc.bcdDevice          = 0x%04x\n", device->bcdDevice);
	printf("desc.iManufacturer      = 0x%02x\n", device->iManufacturer);
	printf("desc.iProduct           = 0x%02x\n", device->iProduct);
	printf("desc.iSerialNumber      = 0x%02x\n", device->iSerialNumber);
	printf("desc.bNumConfigurations = 0x%02x\n", device->bNumConfigurations);
}

void usbh_on_message_decode(uint8_t src, uint8_t len, uint8_t *data)
{
	USBMessage msg;
	msg.src = src;
	msg.len = len<0x8?len:0x8;
	for(int k=0;k<msg.len;k++)
		msg.data[k] = data[k];

	hal_queue_send( usb_msg_queue, &msg);
}

void usbh_pins_init(int DP_P0, int DM_P0, int DP_P1, int DM_P1, int queue_size)
{
  #define USBH_QUEUE_SIZE 100
  static USBMessage /*USB_FAST_DATA*/ usb_msg_queue_buffer[USBH_QUEUE_SIZE]; //NOTE: too much data makes things slower
  usb_msg_queue = hal_queue_create(USBH_QUEUE_SIZE, sizeof(USBMessage), usb_msg_queue_buffer);

  initStates(DP_P0, DM_P0, DP_P1, DM_P1, -1, -1, -1, -1);

  litex_timer_setup((uint32_t) ((double)TIMER_INTERVAL0_SEC * TIMER_SCALE), usb_process);

  set_ondetect_cb(usbh_on_detect);
  set_usb_mess_cb(usbh_on_message_decode);
}
#endif //LITEX_SIMULATION

static void draw_line(int x0, int y0, int x1, int y1, uint32_t color, uint32_t tint)
{
	uintptr_t fb = VIDEO_FRAMEBUFFER_BASE;
	fb += x0*sizeof(color) + y0*FRAME_PITCH;
	accel_linea(accel_line32a_regs, x1-x0, y1-y0, color, tint, 
		(uintptr_t) fb, FRAME_PITCH/4, (uintptr_t) fb, FRAME_PITCH/4, 1, 1);
}

int usbh_on_hidevent_mouse(int dx, int dy, int buttons, int wheel)
{
	static int mousex = FRAME_WIDTH/2, mousey = FRAME_HEIGHT/2;
	int x0 = mousex, y0 = mousey, x1 = mousex+dx, y1 = mousey+dy;

	printf("MOUSE EVENT:\tx=%4d(%+4d),\ty=%4d(%+4d),\tbuttons=0x%02X\n",
		mousex, mousey, dx, dy, buttons);
	
	//clamp coordinates
	if(x1 >= FRAME_WIDTH) x1 = FRAME_WIDTH-1;
	if(x1 < 0) x1 = 0;
	if(y1 >= FRAME_HEIGHT) y1 = FRAME_HEIGHT-1;
	if(y1 < 0) y1 = 0;
	
	if(buttons)
	{
		uint32_t tint = 0x00808080;
		uint32_t color = 0xFF000000;
		color |= (buttons & 1) ? 0x80 : 0; //left button: RED
		color |= (buttons & 2) ? 0x8000 : 0; //right button: GREEN
		color |= (buttons & 4) ? 0x800000: 0; //middle button: BLUE
		draw_line(x0, y0, x1, y1, color, tint);
	}

	mousex = x1;
	mousey = y1;
	return false;
}

extern "C" void wait_vsync();

extern "C" void graphics_app(void)
{
#ifndef DISABLE_HARDWARE_ACCEL 
	static const int DP_P0 = 14; //D+
	static const int DM_P0 = 15; //D-
	usbh_pins_init(DP_P0, DM_P0, -1, -1, USBH_QUEUE_SIZE);
#endif

	//clears screen
	for(int y = 0; y < FRAME_HEIGHT; ++y)
		draw_line(0, y, FRAME_WIDTH, y, 0xFF202050, 0);

	for(;;)
	{
#ifndef DISABLE_HARDWARE_ACCEL 
		usbh_hid_poll(1./60);
#else
		wait_vsync();
#endif
	}
}

#ifndef DISABLE_HARDWARE_ACCEL
//dependencies
#include "usb_host/usb_test/main/usb_host.c"
#include "usb_host/usb_test/main/usb_host_hid.c"
#include "usb_host/usb_test/main/usb_fifo.cpp"
#else

extern "C" int fb_on_mouse_event(int dx, int dy, int buttons, int wheel) //to be called by simulator
{
	printf("mouse event +%d,+%d buttons %d wheel %d\n", dx, dy, buttons, wheel);
	return usbh_on_hidevent_mouse(dx, dy, buttons, wheel);
}
#endif

