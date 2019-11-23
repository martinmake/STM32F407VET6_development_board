#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

#include "driver/tty/singleton.h"

extern "C" int _write(int file, char *data, int len)
{
	(void) file;

	uint8_t status;
	do status = CDC_Transmit_FS((uint8_t*) data, len);
	while (status == USBD_BUSY);

	return len;
}

namespace Driver
{
	Tty::Singleton tty;

	namespace Tty
	{
		Singleton::Singleton(void)
			: fosl::Tty::Base(stdout)
		{
		}

		bool Singleton::initialize(void)
		{
			setvbuf(stdin,  NULL, _IONBF, 0);
			setvbuf(stdout, NULL, _IONBF, 0);
			setvbuf(stderr, NULL, _IONBF, 0);

			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			printf("                                                       \r");
			HAL_Delay(10);
			reset_device();

			INITIALIZATION_OK("TTY");
		}
	}
}
