#ifndef _DRIVER_STATUS_LEDS_H_
#define _DRIVER_STATUS_LEDS_H_

#include "driver/base.h"

#define STATUS_LED_ERROR_GPIO     GPIOA
#define STATUS_LED_ERROR_GPIO_PIN GPIO_PIN_6
#define STATUS_LED_WARNING_GPIO     GPIOA
#define STATUS_LED_WARNING_GPIO_PIN GPIO_PIN_7

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

		class Handle : public Driver::Base
		{
			public: // CONSTRUCTORS
				Handle(void) = default;
			public: // DESTRUCTOR
				~Handle(void) = default;

			public: // METHODS
				bool initialize(void) override;

			public: // OPERATORS
				void operator()(SIGNAL signal);
		};
	}

	extern StatusLeds::Handle status_leds;
}

#endif
