#include "Drivers.hpp"

using namespace FOSL::TTY;
using namespace FOSL::ILI9341;

using namespace Driver;
using namespace Driver::Display::DIMENSIONS;

extern "C" void application(void)
{
	drivers.initialize();

	tty.puts("");
	tty.save_cursor_position();

	display.fill(Color { 0, 0, 0 });

	display.draw_full_rectangle(
		Point { WIDTH / 4, HEIGHT / 4 },
		Size  { WIDTH / 2, HEIGHT / 2 },
		Color { 0, 0, 31 });

	display.draw_pixel(Point { 140, 170 }, Color { 0, 63, 31 });
	display.draw_pixel(Point { 140, 160 }, Color { 0, 63, 31 });
	display.draw_pixel(Point { 130, 170 }, Color { 0, 63, 31 });
	display.draw_pixel(Point { 130, 160 }, Color { 0, 63, 31 });

	// display.horizontal_line(Point { 200, 200 }, 20, Color {  0, 63, 31 });
	// display.vertical_line  (Point { 200, 200 }, 20, Color { 20,  3,  1 });

	// display.circle_outline(Point { 59, 50 }, 40, Color { 0, 63, 31 });
	// display.full_circle   (Point { 50, 58 }, 43, Color { 0,  3,  1 });

	// display.full_triangle(
	// 	Point {  10, 160 },
	// 	Point { 110, 160 },
	// 	Point { 190, 300 },
	// 	Color { 0, 20, 13 });
	// display.triangle_outline(
	// 	Point {  16, 170 },
	// 	Point { 115, 167 },
	// 	Point { 201, 307 },
	// 	Color { 0, 20, 13 });

	// display.puts(
	// 	"HELLO",
	// 	Point { 60, 90 },
	// 	Color { 10, 20, 30 },
	// 	Color { 10,  0,  0 },
	// 	5);

	while (true)
	{
	}
}
