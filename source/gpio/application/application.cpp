#include "drivers.h"

extern "C" int application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace Driver;
		using namespace StatusLeds;

		status_leds(SIGNAL::WARNING);
		HAL_Delay(500);
		status_leds(SIGNAL::ERROR);
		HAL_Delay(500);
	}
}
