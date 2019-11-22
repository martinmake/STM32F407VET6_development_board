#ifndef _APPLICATION_DRIVER_STATUS_LEDS_SINGLETON_H_
#define _APPLICATION_DRIVER_STATUS_LEDS_SINGLETON_H_

#include "driver/base.h"

namespace Driver
{
	namespace STATUS_LEDS
	{
		enum class SIGNAL : uint8_t
		{
			OK,
			SUCCESS,
			WARNING,
			ERROR,
		};

		inline const auto ERROR_GPIO_PORT = GPIOA;
		inline const auto ERROR_GPIO_PIN  = GPIO_PIN_6;
		inline const auto WARNING_GPIO_PORT = GPIOA;
		inline const auto WARNING_GPIO_PIN  = GPIO_PIN_7;
	}

	class StatusLeds : public Driver::Base
	{
		public: // CONSTRUCTORS
			StatusLeds(void);
		public: // DESTRUCTOR
			~StatusLeds(void) = default;

		public: // METHODS
			bool initialize(void) override;

		public: // OPERATORS
			StatusLeds& operator()(STATUS_LEDS::SIGNAL signal);
	};

	extern StatusLeds status_leds;
}

#endif
