#ifndef _APPLICATION_DRIVER_DISPLAY_HANDLE_H_
#define _APPLICATION_DRIVER_DISPLAY_HANDLE_H_

#include <fosl/ili9341/base.h>

#include "driver/base.h"

#include "driver/display/defs.h"

namespace Driver
{
	namespace Display
	{
		class Handle : public Driver::Base, public fosl::Ili9341::Base
		{
			public: // CONSTRUCTORS
				Handle(void);
			public: // DESTRUCTOR
				~Handle(void) = default;

			public: // METHODS
				bool initialize(void);
				//
				void send(fosl::Ili9341::COMMAND command) override;
				void send(fosl::Ili9341::Color color) override;
				void send(uint8_t data) override;
				void delay_ms(uint8_t ms) override;
		};
	}

	extern Display::Handle display;
}

#endif
