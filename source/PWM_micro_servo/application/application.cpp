#include "Drivers.hpp"

using namespace TTY;

using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	micro_servo.set_pulse_width(1000);
	HAL_Delay(4000);

	tty.putchar('\n');
	tty.puts("BEGIN TEST");

	for (uint16_t pulse_width = 1000; pulse_width <= 1100; pulse_width++)
	{
		micro_servo.set_pulse_width(pulse_width);
		tty.printf("%u\n", pulse_width);
		HAL_Delay(100);
	}
	for (uint16_t pulse_width = 1100; pulse_width >= 1000; pulse_width--)
	{
		micro_servo.set_pulse_width(pulse_width);
		tty.printf("%u\n", pulse_width);
		HAL_Delay(100);
	}

	tty.putchar('\n');
	tty.puts("END TEST");

	while (true)
	{
	}
}
