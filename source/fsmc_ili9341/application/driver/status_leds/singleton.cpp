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
			using namespace GPIO;

			switch (signal)
			{
				case SIGNAL::OK:
					HAL_GPIO_WritePin(  ERROR::PORT,   ERROR::PIN, GPIO_PIN_SET);
					HAL_GPIO_WritePin(WARNING::PORT, WARNING::PIN, GPIO_PIN_SET);
					break;
				case SIGNAL::SUCCESS:
					HAL_GPIO_WritePin(  ERROR::PORT,   ERROR::PIN, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(WARNING::PORT, WARNING::PIN, GPIO_PIN_RESET);
					break;
				case SIGNAL::WARNING:
					HAL_GPIO_WritePin(  ERROR::PORT,   ERROR::PIN, GPIO_PIN_SET);
					HAL_GPIO_WritePin(WARNING::PORT, WARNING::PIN, GPIO_PIN_RESET);
					break;
				case SIGNAL::ERROR:
					HAL_GPIO_WritePin(  ERROR::PORT,   ERROR::PIN, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(WARNING::PORT, WARNING::PIN, GPIO_PIN_SET);
					break;
			}

			return *this;
		}
	}
}
