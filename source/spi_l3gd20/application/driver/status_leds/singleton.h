#ifndef _DRIVER_STATUS_LEDS_SINGLETON_H_
#define _DRIVER_STATUS_LEDS_SINGLETON_H_

#include "driver/base.h"
#include "driver/tty.h"

#include "driver/status_leds/signal.h"

namespace Driver
{
	namespace StatusLeds
	{
		class Singleton : public Driver::Base
		{
			public:
				Singleton(void) = default;
			public:
				~Singleton(void) = default;

			public:
				bool initialize(void) override;

			public:
				Singleton& operator()(SIGNAL signal);
		};
	}

	extern StatusLeds::Singleton status_leds;
}

#endif
