#ifndef _DRIVER_DISPLAY_SINGLETON_H_
#define _DRIVER_DISPLAY_SINGLETON_H_

#include <fosl/ili9341/base.h>

#include "driver/base.h"

#include "driver/display/dimensions.h"

namespace Driver
{
	namespace Display
	{
		class Singleton : public Driver::Base, public fosl::Ili9341::Base
		{
			public: // CONSTRUCTORS
				Singleton(void);
			public: // DESTRUCTOR
				~Singleton(void) = default;

			public: // METHODS
				bool initialize(void);
				//
				void send(fosl::Ili9341::COMMAND command) override;
				void send(fosl::Ili9341::Color color) override;
				void send(uint8_t data) override;
				void delay_ms(uint8_t ms) override;
		};
	}

	extern Display::Singleton display;
}

#endif
