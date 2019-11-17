#ifndef _APPLICATION_DRIVER_STATUS_LEDS_SINGLETON_H_
#define _APPLICATION_DRIVER_STATUS_LEDS_SINGLETON_H_

#include "driver/base.h"
#include "driver/status_leds/defs.h"

namespace Driver
{
	namespace StatusLeds
	{
		class Singleton : public Driver::Base
		{
			public: // CONSTRUCTORS
				Singleton(void);
			public: // DESTRUCTOR
				~Singleton(void) = default;

			public: // METHODS
				bool initialize(void) override;

			public: // OPERATORS
				Singleton& operator()(SIGNAL signal);
		};
	}

	extern StatusLeds::Singleton status_leds;
}

#endif
