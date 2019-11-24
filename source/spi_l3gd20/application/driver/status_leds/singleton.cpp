#include "driver/status_leds/singleton.h"

namespace Driver
{
	StatusLeds::Singleton status_leds;

	namespace StatusLeds
	{
		bool Singleton::initialize(void)
		{
			status_leds(SIGNAL::OK);

			INITIALIZATION_OK("STATUS LEDS");
		}
		Singleton& Singleton::operator()(SIGNAL signal)
		{
			switch (signal)
			{
				case SIGNAL::OK:
					HAL_GPIO_WritePin(LED_ERROR_GPIO_Port,   LED_ERROR_Pin,   GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_WARNING_GPIO_Port, LED_WARNING_Pin, GPIO_PIN_SET);
					break;
				case SIGNAL::SUCCESS:
					HAL_GPIO_WritePin(LED_ERROR_GPIO_Port,   LED_ERROR_Pin,   GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_WARNING_GPIO_Port, LED_WARNING_Pin, GPIO_PIN_RESET);
					break;
				case SIGNAL::WARNING:
					HAL_GPIO_WritePin(LED_ERROR_GPIO_Port,   LED_ERROR_Pin,   GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED_WARNING_GPIO_Port, LED_WARNING_Pin, GPIO_PIN_RESET);
					break;
				case SIGNAL::ERROR:
					HAL_GPIO_WritePin(LED_ERROR_GPIO_Port,   LED_ERROR_Pin,   GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_WARNING_GPIO_Port, LED_WARNING_Pin, GPIO_PIN_SET);
					break;
			}

			return *this;
		}
	}
}
