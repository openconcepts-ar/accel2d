
#ifndef USB_HOST_H
#define USB_HOST_H

#define TIMER_INTERVAL0_SEC   (0.001) // sample test interval for the first timer


// non configured device -  must be zero
#define  ZERO_USB_ADDRESS   0

// any number less 127, but no zero
#define  ASSIGNED_USB_ADDRESS    3

				  

void printState();
void usb_process();

#define  NUM_USB 1

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



#endif
