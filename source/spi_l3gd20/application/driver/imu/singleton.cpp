#include "driver/imu/singleton.h"

namespace Driver
{
	Imu::Singleton imu;

	namespace Imu
	{
		// METHODS
		bool Singleton::initialize(void)
		{
			INITIALIZATION_OK("IMU");
		}
		//
		void Singleton::write_register_8bit(fosl::L3gd20::REGISTER address, uint8_t value)
		{
		}
		//
		uint8_t Singleton::read_register_8bit(fosl::L3gd20::REGISTER address)
		{
		}
	}
}
