#ifndef _DRIVER_STATUS_LEDS_SIGNAL_H_
#define _DRIVER_STATUS_LEDS_SIGNAL_H_

namespace Driver
{
	namespace StatusLeds
	{
		enum class SIGNAL : uint8_t
		{
			OK,
			SUCCESS,
			WARNING,
			ERROR,
		};
	}
}

#endif
