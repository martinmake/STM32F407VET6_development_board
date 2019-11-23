#include "drivers.h"

using namespace Driver;

Drivers drivers;

bool Drivers::initialize(void)
{
	bool has_failed = false;

	if (!tty        .initialize()) has_failed = true;
	if (!status_leds.initialize()) has_failed = true;
	if (!knob       .initialize()) has_failed = true;
	if (!micro_servo.initialize()) has_failed = true;

	#ifdef DEBUG
		using namespace fosl::Tty;
		tty(DISPLAY_ATTRIBUTE::RESET);
		tty.putchar('\n');
	#endif

	return has_failed ? ERROR : OK;
}
