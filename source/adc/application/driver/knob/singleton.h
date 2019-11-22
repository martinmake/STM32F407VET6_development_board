#ifndef _DRIVER_KNOB_SINGLETON_H_
#define _DRIVER_KNOB_SINGLETON_H_

#include "driver/base.h"
#include "driver/tty.h"

#include "driver/knob/gpio.h"

namespace Driver
{
	namespace Knob
	{
		class Singleton : public Driver::Base
		{
			public: // CONSTRUCTORS
				Singleton(void) = default;
			public: // DESTRUCTOR
				~Singleton(void) = default;

			public: // VARIABLES
			private:
				uint8_t value;

			public: // GETTERS
				uint8_t get_position(void);

			public: // OPERATORS
				bool initialize(void) override;
		};
	}

	extern Knob::Singleton knob;
}

#endif
