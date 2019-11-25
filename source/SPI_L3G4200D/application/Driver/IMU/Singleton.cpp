#include "Driver/IMU/Singleton.hpp"

namespace Driver
{
	IMU::Singleton imu;

	namespace IMU
	{
		using namespace FOSL::L3G4200D;

		// METHODS
		bool Singleton::initialize(void)
		{
			if (!is_connected())
				INITIALIZATION_FAILED("IMU", "CHIP NOT DETECTED");

			L3G4200D::Base::initialize({ SCALE::DPS250 });

			INITIALIZATION_OK("IMU");
		}
		//
		void Singleton::write_8bit(L3G4200D::REGISTER address, uint8_t value)
		{
			chip_select(true);

			uint8_t write_command = (uint8_t) address;
			HAL_SPI_Transmit(&hspi2, &write_command, sizeof(write_command), spi_timeout_ms);
			HAL_SPI_Transmit(&hspi2, &value,         sizeof(value),         spi_timeout_ms);

			chip_select(false);
		}
		//
		uint8_t Singleton::read_8bit(L3G4200D::REGISTER address)
		{
			uint8_t value;

			chip_select(true);

			uint8_t read_command = (uint8_t) address | BIT(7);
			HAL_SPI_Transmit(&hspi2, &read_command, sizeof(read_command), spi_timeout_ms);
			HAL_SPI_Receive (&hspi2, &value,        sizeof(value),        spi_timeout_ms);

			chip_select(false);

			return value;
		}
	}
}
