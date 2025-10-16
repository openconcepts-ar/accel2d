#ifndef USB_HOST_H
#define USB_HOST_H

#define  NUM_USB 1 //max number of supported hosts, up to 4

#define TIMER_INTERVAL0_SEC		(1./1000)	// sample test interval for the first timer (in seconds)
#define  ZERO_USB_ADDRESS		0			// non configured device -  must be zero
#define  ASSIGNED_USB_ADDRESS	3 			// any number less 127, but no zero

void initStates(int DP0,int DM0,int DP1,int DM1,int DP2,int DM2,int DP3,int DM3);
void printState();
void usb_process();

typedef __packed struct
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} sDevDesc;

typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint16_t wLength;
	uint8_t bNumIntf;
	uint8_t bCV;
	uint8_t bIndex;
	uint8_t bAttr;
	uint8_t bMaxPower;
} sCfgDesc;
typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint8_t iNum;
	uint8_t iAltString;
	uint8_t bEndPoints;
	uint8_t iClass;
	uint8_t iSub;
	uint8_t iProto;
	uint8_t iIndex;
} sIntfDesc;
typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint8_t bEPAdd;
	uint8_t bAttr;
	uint16_t wPayLoad;               /* low-speed this must be 0x08 */
	uint8_t bInterval;
} sEPDesc;

typedef __packed struct
{
  uint8_t   bLength;
  uint8_t   bDescriptorType;
  uint16_t  bcdHID;
  uint8_t   bCountryCode;
  uint8_t   bNumDescriptors;
  uint8_t   bReportDescriptorType;
  uint8_t   wItemLengthL;
  uint8_t   wItemLengthH;
} HIDDescriptor;

typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint16_t wLang;
} sStrDesc;


typedef void (*onusbmesscb_t)(uint8_t src,uint8_t len,uint8_t *data);
void set_usb_mess_cb( onusbmesscb_t onUSBMessCb );

typedef void (*ondetectcb_t)(uint8_t usbNum, void *device);
void set_ondetect_cb( ondetectcb_t cb );

//HID management
typedef enum
{
  USB_HID_PROTO_NONE = 0x00,
  USB_HID_PROTO_KEYBOARD = 0x01,
  USB_HID_PROTO_MOUSE = 0x02,
} hid_protocol_t;

extern hid_protocol_t hid_types[];

typedef struct
{
  int modifier, key;
  char inputchar;
  bool pressed;
} hid_event_keyboard;

typedef struct
{
  int16_t x, y, wheel;
  uint8_t buttons;
} hid_event_mouse;

typedef union
{
  hid_event_keyboard k;
  hid_event_mouse m;
} hid_event;

hid_protocol_t usbh_hid_process(hid_event *evt, int prevupdated, float dt);
hid_protocol_t usbh_hid_poll(float dt); //call with time elapsed

#endif
