#include "Driver/Display/Singleton.hpp"

namespace Driver
{
	Display::Singleton display;

	namespace Display
	{
		using namespace ILI9341;
		using namespace ILI9341::Color;

		// METHODS
		bool Singleton::initialize(void)
		{
			ILI9341::Base<RGB565>::initialize();

			display.set(ROTATION::REVERSE_PORTRAIT);
			// display.set(ROTATION::LANDSCAPE);
			display.draw_full_rectangle(
				Point { 0,                   0                    },
				Size  { display.get_width(), display.get_height() },
				RGB565 { 0, 0, 0 });

			// TMP TEST
			// display.draw_full_rectangle(
			// 	Point { (uint16_t) 0,                       (uint16_t) display.get_height()     },
			// 	Size  { (uint16_t) display.get_width() - 1, (uint16_t) display.get_height() - 1 },
			// 	RGB565 { 0, 0, 0 });


			INITIALIZATION_OK("DISPLAY");
		}

		void Singleton::send(FOSL::ILI9341::COMMAND command)
		{
			// 0b01100000000000000000000000000000
			*((volatile uint16_t*) 0x60000000) = (uint16_t) command;
		}
		void Singleton::send(FOSL::ILI9341::Color::RGB565 color)
		{
			// 0b01100000000010000000000000000000
			*((volatile uint16_t*) 0x60080000) = (uint16_t) color;
		}
		void Singleton::send(uint8_t data)
		{
			// 0b01100000000010000000000000000000
			*((volatile uint16_t*) 0x60080000) = (uint16_t) data;
		}
		void Singleton::delay_ms(uint8_t ms)
		{
			HAL_Delay(ms);
		}
	}
}
