#ifndef _EVALUATION_DRIVER_STATUS_LEDS_H_
#define _EVALUATION_DRIVER_STATUS_LEDS_H_

#include "driver/base.h"
#include "driver/tty.h"

namespace Driver
{
	namespace StatusLeds
	{
		enum class SIGNAL : uint8_t
		{
			OK,
			SUCCESS,
			WARNING,
			ERROR,
		};

		inline const auto ERROR_GPIO_PORT = GPIOA;
		inline const auto ERROR_GPIO_PIN  = GPIO_PIN_6;
		inline const auto WARNING_GPIO_PORT = GPIOA;
		inline const auto WARNING_GPIO_PIN  = GPIO_PIN_7;

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
