#ifndef _DRIVER_STATUS_LEDS_SINGLETON_HPP_
#define _DRIVER_STATUS_LEDS_SINGLETON_HPP_

#include "Driver/Base.hpp"
#include "Driver/TTY.hpp"

#include "Driver/StatusLeds/SIGNAL.hpp"

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
