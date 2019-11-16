#ifndef _EVALUATION_DRIVER_STATUS_LEDS_DEFS_H_
#define _EVALUATION_DRIVER_STATUS_LEDS_DEFS_H_

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
	}
}

#endif
