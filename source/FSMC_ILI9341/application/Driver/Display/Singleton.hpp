#ifndef _DRIVER_DISPLAY_SINGLETON_HPP_
#define _DRIVER_DISPLAY_SINGLETON_HPP_

#include <FOSL/ILI9341.hpp>

#include "Driver/Base.hpp"
#include "Driver/TTY.hpp"

#include "Driver/Display/DIMENSIONS.hpp"

namespace Driver
{
	namespace Display
	{
		class Singleton : public Driver::Base, public FOSL::ILI9341::Base
		{
			public: // CONSTRUCTORS
				Singleton(void);
			public: // DESTRUCTORS
				~Singleton(void) = default;

			public: // METHODS
				bool initialize(void) override;

				void send(ILI9341::COMMAND command) override;
				void send(ILI9341::Color color) override;
				void send(uint8_t data) override;
				void delay_ms(uint8_t ms) override;
		};
	}

	extern Display::Singleton display;
}

#endif
