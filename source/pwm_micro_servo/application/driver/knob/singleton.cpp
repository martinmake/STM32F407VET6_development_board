#include "adc.h"

#include "driver/knob/singleton.h"

namespace Driver
{
	Knob::Singleton knob;

	namespace Knob
	{
		// METHODS
		bool Singleton::initialize(void)
		{
			value = 0;

			INITIALIZATION_OK("KNOB");
		}
		uint8_t Singleton::get_position(void)
		{
			HAL_ADC_Start(&hadc1);

			if (HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
				value = HAL_ADC_GetValue(&hadc1);

			HAL_ADC_Stop(&hadc1);

			#ifdef DEBUG
				tty.printf("KNOB POSITION: % 3u\r", value);
			#endif

			return value;
		}
	}
}
