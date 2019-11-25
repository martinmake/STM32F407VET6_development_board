#include "Driver/Display/Singleton.hpp"

namespace Driver
{
	Display::Singleton display;

	namespace Display
	{
		using namespace ILI9341;

		// CONSTRUCTORS
		Singleton::Singleton(void)
			: FOSL::ILI9341::Base(DIMENSIONS::WIDTH, DIMENSIONS::HEIGHT)
		{
		}

		// METHODS
		bool Singleton::initialize(void)
		{
			ILI9341::Base::initialize();

			display.set(ROTATION::PORTRAIT);
			display.fill(Color { 0, 0, 0 });

			INITIALIZATION_OK("DISPLAY");
		}

		void Singleton::send(ILI9341::COMMAND command)
		{
			// 0b01100000000000000000000000000000
			*((volatile uint16_t*) 0x60000000) = (uint16_t) command;
		}
		void Singleton::send(ILI9341::Color color)
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
