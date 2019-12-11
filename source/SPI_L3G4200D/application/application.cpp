#include "Drivers.hpp"

using namespace TTY;

using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	tty.save_cursor_position();
	while (true)
	{
		imu.read_angular_rate();

		tty.restore_cursor_position();
		tty.printf("    ┌    ┐\n");
		tty.printf("    │%+04d│\n", imu.angular_rate.x);
		tty.printf("α = │%+04d│\n", imu.angular_rate.y);
		tty.printf("    │%+04d│\n", imu.angular_rate.z);
		tty.printf("    └    ┘\n");
		tty.set_cursor_position(0, 0);
		HAL_Delay(200);
	}
}
