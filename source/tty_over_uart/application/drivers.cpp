#include "drivers.h"

using namespace Driver;

Drivers drivers;

bool Drivers::initialize(void)
{
	bool has_failed = false;

	HAL_Init();

	if (!tty        .initialize()) has_failed = true;
	if (!status_leds.initialize()) has_failed = true;

	if (has_failed) return ERROR;

	return OK;
}
