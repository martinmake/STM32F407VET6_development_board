#include "drivers.h"

using namespace fosl;
using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace fosl::Tty;

		uint16_t pulse_width = 1000 + knob.get_position() * 1000 / 255;
		micro_servo.set_pulse_width(
			between(pulse_width, 1400, 1600)
			? 1500
			: pulse_width);

		HAL_Delay(20);
	}
}
