#include "adc.h"
#include "tim.h"

#include "driver/dimmer/singleton.h"

namespace Driver
{
	Dimmer::Singleton dimmer;

	namespace Dimmer
	{
		// METHODS
		bool Singleton::initialize(void)
		{
			value = 0;
			HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

			INITIALIZATION_OK("DIMMER");
		}
		void Singleton::update_brightness(void)
		{
			HAL_ADC_Start(&hadc1);

			if (HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
				value = 0.2 * value + 0.8 * HAL_ADC_GetValue(&hadc1);

			#ifdef DEBUG
				tty.printf("DIMMER POSITION: % 3u\r", value);
			#endif

			htim4.Instance->CCR1 = value * 2000 / 255;

			HAL_ADC_Stop(&hadc1);
		}
	}
}
