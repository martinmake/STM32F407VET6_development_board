#include "drivers.h"

using namespace fosl;
using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace fosl::Tty;

		util::temporary();

		tty.printf("KNOB POSITION: % 3u", knob.get_position());
		tty.putchar('\r');
		HAL_Delay(20);
	}
}
