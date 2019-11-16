#ifndef _EVALUATION_DRIVER_STATUS_LEDS_HANDLE_H_
#define _EVALUATION_DRIVER_STATUS_LEDS_HANDLE_H_

#include "driver/base.h"
#include "driver/tty/handle.h"

#include "driver/status_leds/defs.h"

namespace Driver
{
	namespace StatusLeds
	{
		class Handle : public Driver::Base
		{
			public:
				Handle(void) = default;
			public:
				~Handle(void) = default;

			public:
				bool initialize(void) override;

			public:
				Handle& operator()(SIGNAL signal);
		};
	}

	extern StatusLeds::Handle status_leds;
}

#endif
