#ifndef _DRIVER_DIMMER_SINGLETON_H_
#define _DRIVER_DIMMER_SINGLETON_H_

#include "driver/base.h"
#include "driver/tty.h"

#include "driver/dimmer/gpio.h"

namespace Driver
{
	namespace Dimmer
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

			public: // METHODS
				void update_brightness(void);

			public: // OPERATORS
				bool initialize(void) override;
		};
	}

	extern Dimmer::Singleton dimmer;
}

#endif
