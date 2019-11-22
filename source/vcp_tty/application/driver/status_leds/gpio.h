#ifndef _DRIVER_STATUS_LEDS_GPIO_H_
#define _DRIVER_STATUS_LEDS_GPIO_H_

namespace Driver
{
	namespace StatusLeds
	{
		namespace GPIO
		{
			namespace ERROR
			{
				inline const auto PORT = GPIOA;
				inline const auto PIN  = GPIO_PIN_6;
			}
			namespace WARNING
			{
				inline const auto PORT = GPIOA;
				inline const auto PIN  = GPIO_PIN_7;
			}
		}
	}
}

#endif
