#include "drivers.h"

using namespace Driver;

Drivers drivers;

Drivers::Drivers(void)
{
	static bool are_constructed = false;

	assert(!are_constructed)

	are_constructed = true;
}

bool Drivers::initialize(void)
{
	bool has_failed = false;

	if (!status_leds.initialize()) has_failed = true;

	if (has_failed) return ERROR;

	return OK;
}
