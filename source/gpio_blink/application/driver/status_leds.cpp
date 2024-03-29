#include "driver/status_leds.h"

namespace Driver
{
	using namespace STATUS_LEDS;

	StatusLeds status_leds;

	StatusLeds::StatusLeds(void)
	{
		static bool is_constructed = false;

		assert(!is_constructed)

		is_constructed = true;
	}

	bool StatusLeds::initialize(void)
	{
		status_leds(SIGNAL::OK);
		INITIALIZATION_OK("STATUS LEDS");
	}

	StatusLeds& StatusLeds::operator()(SIGNAL signal)
	{
		switch (signal)
		{
			case SIGNAL::OK:
				HAL_GPIO_WritePin(  ERROR_GPIO_PORT,   ERROR_GPIO_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WARNING_GPIO_PORT, WARNING_GPIO_PIN, GPIO_PIN_SET);
				break;
			case SIGNAL::SUCCESS:
				HAL_GPIO_WritePin(  ERROR_GPIO_PORT,   ERROR_GPIO_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WARNING_GPIO_PORT, WARNING_GPIO_PIN, GPIO_PIN_RESET);
				break;
			case SIGNAL::WARNING:
				HAL_GPIO_WritePin(  ERROR_GPIO_PORT,   ERROR_GPIO_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WARNING_GPIO_PORT, WARNING_GPIO_PIN, GPIO_PIN_RESET);
				break;
			case SIGNAL::ERROR:
				HAL_GPIO_WritePin(  ERROR_GPIO_PORT,   ERROR_GPIO_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WARNING_GPIO_PORT, WARNING_GPIO_PIN, GPIO_PIN_SET);
				break;
		}

		return *this;
	}
}
