#ifndef _DRIVER_MICRO_SERVO_SINGLETON_HPP_
#define _DRIVER_MICRO_SERVO_SINGLETON_HPP_

#include "Driver/Base.hpp"
#include "Driver/TTY.hpp"

namespace Driver
{
	namespace MicroServo
	{
		class Singleton : public Driver::Base
		{
			public: // CONSTRUCTORS
				Singleton(void) = default;
			public: // DESTRUCTOR
				~Singleton(void) = default;

			public: // GETTERS
			public: // SETTERS
				void set_pulse_width(uint16_t pulse_width);

			public: // METHODS
				bool initialize(void) override;
		};

		#include "Driver/MicroServo/Singleton-impl.hpp"
	}

	extern MicroServo::Singleton micro_servo;
}

#endif
