#include "drivers.h"

#define L3GD20_WHO_AM_I     0b11010010

#define L3GD20_REG_WHO_AM_I 0x0F
#define L3GD20_REG_CTRL_REG1 0x20

using namespace fosl;
using namespace fosl::Tty;

using namespace Driver;

uint8_t spi_read(uint8_t address)
{
	uint8_t data;

	HAL_GPIO_WritePin(L3GD20_CS_GPIO_Port, L3GD20_CS_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);

	uint8_t read_command = address | 0b10000000;
	uint8_t timeout = 10;
	HAL_SPI_Transmit(&hspi2, &read_command, sizeof(read_command), timeout);
	HAL_SPI_Receive (&hspi2, &data,         sizeof(data),         timeout);

	HAL_GPIO_WritePin(L3GD20_CS_GPIO_Port, L3GD20_CS_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	return data;
}

extern "C" void application(void)
{
	drivers.initialize();

	uint8_t who_am_i;
	do
	{
		who_am_i = spi_read(L3GD20_REG_WHO_AM_I);
		printf("READ: 0x%02X\r", who_am_i);
	} while (who_am_i != L3GD20_WHO_AM_I);

	while (true)
	{
	}
}
