#ifndef _DRIVER_IMU_SINGLETON_HPP_
#define _DRIVER_IMU_SINGLETON_HPP_

#include <FOSL/L3G4200D/Base.hpp>

#include "Driver/Base.hpp"
#include "Driver/TTY.hpp"

namespace Driver
{
	namespace IMU
	{
		class Singleton : public Driver::Base, public FOSL::L3G4200D::Base
		{
			public: // CONSTRUCTORS
				Singleton(void) = default;
			public: // DESTRUCTOR
				~Singleton(void) = default;

			public: // CONSTANTS
				const uint8_t spi_timeout_ms = 10;

			public: // METHODS
				bool initialize(void) override;
				//
				void write_8bit(L3G4200D::REGISTER address, uint8_t value) override;
				//
				uint8_t read_8bit(L3G4200D::REGISTER address) override;
				//
				void chip_select(bool select);
		};

		#include "Driver/IMU/Singleton-impl.hpp"
	}

	extern IMU::Singleton imu;
}

#endif
