#ifndef _DRIVER_IMU_SINGLETON_H_
#define _DRIVER_IMU_SINGLETON_H_

#include <fosl/l3gd20/base.h>

#include "driver/base.h"
#include "driver/tty.h"

namespace Driver
{
	namespace Imu
	{
		class Singleton : public Driver::Base, public fosl::L3gd20::Spi::Base
		{
			public:
				Singleton(void) = default;
			public:
				~Singleton(void) = default;

			public:
				bool initialize(void) override;
				//
				void write_register_8bit(fosl::L3gd20::REGISTER address, uint8_t value) override;
				//
				uint8_t read_register_8bit(fosl::L3gd20::REGISTER address) override;
				//
				void chip_select(bool select) override;
		};

		#include "driver/imu/singleton-impl.h"
	}

	extern Imu::Singleton imu;
}

#endif
