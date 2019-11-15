#ifndef _EVALUATION_DRIVER_STATUS_LEDS_H_
#define _EVALUATION_DRIVER_STATUS_LEDS_H_

#include "driver/base.h"
#include "driver/tty.h"

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
	}

	class StatusLeds : public Driver::Base
	{
		public: // CONSTRUCTORS
			StatusLeds(void) = default;
		public: // DESTRUCTOR
			~StatusLeds(void) = default;

		public: // METHODS
			bool initialize(void) override;
			//
			void signal(STATUS_LEDS::SIGNAL signal);
	};

	extern StatusLeds status_leds;
}

#endif
