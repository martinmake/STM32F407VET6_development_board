#include "drivers.h"

extern "C" int application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace Driver;
		using namespace Driver::StatusLeds;

		status_leds(StatusLeds::SIGNAL::WARNING);
		HAL_Delay(500);
		status_leds(StatusLeds::SIGNAL::ERROR);
		HAL_Delay(500);
	}
}
