#include "Drivers.hpp"

using namespace FOSL::TTY;
using namespace FOSL::ILI9341;
using namespace FOSL::ILI9341::Color;

using namespace Driver;

extern "C" int application(void)
{
	drivers.initialize();

	tty.puts("");
	tty.save_cursor_position();

	// display.draw_full_rectangle(
	// 	Point { display.get_width() / 4, display.get_height() / 4 },
	// 	Size  { display.get_width() / 2, display.get_height() / 2 },
	// 	RGB565 { 0, 0, 31 });

	// display.draw_pixel(Point { 140, 170 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 140, 160 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 130, 170 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 130, 160 }, RGB565 { 0, 63, 31 });

	// display.draw_pixel(Point { 0, 0 }, RGB565 { 0, 63, 31 });
	// // display.draw_pixel(Point { 1, 1 }, RGB565 { 0, 63, 31 });
	// // display.draw_pixel(Point { 2, 2 }, RGB565 { 0, 63, 31 });
	// // display.draw_pixel(Point { 3, 3 }, RGB565 { 0, 63, 31 });

	// display.draw_pixel(Point { 239, 319 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 238, 318 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 237, 317 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 236, 316 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 235, 315 }, RGB565 { 0, 63, 31 });
	// display.draw_pixel(Point { 234, 314 }, RGB565 { 0, 63, 31 });

	// {
	// 	Point p { 0, 0 };
	// 	RGB565 c { 0, 0, 0 };
	// 	while (p.y != 320)
	// 	{
	// 		while (p.x != 240)
	// 		{
	// 			display.draw_pixel(p, c);
	// 			c = (((uint16_t) c) + 1);

	// 			p.x++;
	// 		}

	// 		p.x = 0;
	// 		p.y++;
	// 	}
	// }

	RGB565 c = { 31, 0, 0 };
	for (Point p = { 0, 0 }; p.y != display.get_height(); p.y++)
	{
		for (p.x = 0; p.x != display.get_width(); p.x++)
		{
			display.draw_pixel(p, c);

			     if (c.r == 31 && c.g ==  0 && c.b ==  0) c.g++;
			else if (c.r == 31 && c.g <  63 && c.b ==  0) c.g++;
			else if (c.r == 31 && c.g == 63 && c.b ==  0) c.r--;
			else if (c.r  >  0 && c.g == 63 && c.b ==  0) c.r--;
			else if (c.r ==  0 && c.g == 63 && c.b ==  0) c.b++;
			else if (c.r ==  0 && c.g == 63 && c.b <  31) c.b++;
			else if (c.r ==  0 && c.g == 63 && c.b == 31) c.g--;
			else if (c.r ==  0 && c.g  >  0 && c.b == 31) c.g--;
			else if (c.r ==  0 && c.g ==  0 && c.b == 31) c.r++;
			else if (c.r <  31 && c.g ==  0 && c.b == 31) c.r++;
			else if (c.r == 31 && c.g ==  0 && c.b == 31) c.b--;
			else if (c.r == 31 && c.g ==  0 && c.b  >  0) c.b--;
		}
	}
	return 0;

	{
		Point p { 0, 0 };
		// for (uint8_t offset = 0; offset < 64; offset++)
		for (uint8_t offset = 0; offset < display.get_height(); offset++)
		{
			RGB565 c { 31, 0, 0 };

			while (c.g < 63)
			{
				display.draw_pixel(p, c);

				c.g++;
				p.x++;
			} display.draw_pixel(p, c); p.x++;
			while (c.r > 0)
			{
				display.draw_pixel(p, c);

				c.r--;
				p.x++;
			} display.draw_pixel(p, c); p.x++;
			while (c.b < 31)
			{
				display.draw_pixel(p, c);

				c.b++;
				p.x++;
			} display.draw_pixel(p, c); p.x++;
			while (c.g > 0)
			{
				display.draw_pixel(p, c);

				c.g--;
				p.x++;
			} display.draw_pixel(p, c); p.x++;
			while (c.r < 31)
			{
				display.draw_pixel(p, c);

				c.r++;
				p.x++;
			} display.draw_pixel(p, c); p.x++;
			while (c.b > 0)
			{
				display.draw_pixel(p, c);

				c.b--;
				p.x++;
			} display.draw_pixel(p, c); p.x++;

			tty.printf("%u\n", p.x);
			p.x = 0;
			p.y++;
			// HAL_Delay(5);
		}
	}

	// { Point p {0, 0};
	// 	while (p.y != 320 && p.x != 240)
	// 	{
	// 		display.draw_pixel(p, RGB565 { 0, 0, 31 });
	// 		HAL_Delay(5);

	// 		p.x++;
	// 		p.y++;
	// 	}
	// }

	// { Point p { 239, 319 };
	// 	while (p.y != 0 && p.x != 0)
	// 	{
	// 		display.draw_pixel(p, RGB565 { 31, 0, 31 });
	// 		HAL_Delay(5);

	// 		p.x--;
	// 		p.y--;
	// 	}
	// }

	while (true)
	{
	}
}
