#include "drivers.h"

using namespace Driver;

Drivers drivers;

bool Drivers::initialize(void)
{
	bool has_failed = false;

	if (!tty        .initialize()) has_failed = true;
	if (!status_leds.initialize()) has_failed = true;
	if (!dimmer     .initialize()) has_failed = true;

	using namespace fosl::Tty;
	tty(DISPLAY_ATTRIBUTE::RESET);
	tty.putchar('\n');

	return has_failed ? ERROR : OK;
}
