#include "drivers.h"

using namespace fosl;
using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace fosl::Tty;

		tty(DISPLAY_ATTRIBUTE::BOLD);

		dimmer.update_brightness();
		HAL_Delay(20);
	}
}
