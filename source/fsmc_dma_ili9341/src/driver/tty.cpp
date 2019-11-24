#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

#include "driver/tty.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

extern "C"
{
	int _read(int file, char *data, int len)
	{
		(void) file;

		// TODO

		return 0;
	}
	int _write(int file, char *data, int len)
	{
		(void) file;

		while (CDC_Transmit_FS((uint8_t*) data, len) == USBD_BUSY) { }

		return len;
	}
}

namespace Driver
{
	using namespace Lib;
	using namespace TTY;

	Tty tty;

	bool Tty::initialize(void)
	{
		setvbuf(stdin,  NULL, _IONBF, 0);
		setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);

		reset_device();

		INITIALIZATION_OK("TTY");
	}
}
