#ifndef _DRIVER_STATUS_LEDS_SIGNAL_HPP_
#define _DRIVER_STATUS_LEDS_SIGNAL_HPP_

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
