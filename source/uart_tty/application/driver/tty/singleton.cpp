#include "usart.h"

#include "driver/tty/singleton.h"

extern "C" int _write(int file, char *data, int len)
{
	(void) file;

	HAL_StatusTypeDef status =
		HAL_UART_Transmit(&huart1, (uint8_t*) data, len, HAL_MAX_DELAY);

	int bytes_sent = status == HAL_OK ? len : 0;
	return bytes_sent;
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
