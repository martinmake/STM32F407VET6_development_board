#include "drivers.h"

extern "C" int application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace Driver;
		using namespace Driver::STATUS_LEDS;

		status_leds(SIGNAL::WARNING);
		HAL_Delay(500);
		status_leds(SIGNAL::ERROR);
		HAL_Delay(500);
	}
}
