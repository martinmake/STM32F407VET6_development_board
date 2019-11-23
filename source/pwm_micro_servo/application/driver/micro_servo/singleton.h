#ifndef _DRIVER_MICRO_SERVO_SINGLETON_H_
#define _DRIVER_MICRO_SERVO_SINGLETON_H_

#include "driver/base.h"
#include "driver/tty.h"

#include "driver/micro_servo/gpio.h"

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
				void set_pulse_width(uint16_t new_pulse_width);

			public: // METHODS
				bool initialize(void) override;
		};

		#include "driver/micro_servo/singleton-impl.h"
	}

	extern MicroServo::Singleton micro_servo;
}

#endif
