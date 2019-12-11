#include "tim.h"

#include "Driver/MicroServo/Singleton.hpp"

namespace Driver
{
	MicroServo::Singleton micro_servo;

	namespace MicroServo
	{
		// METHODS
		bool Singleton::initialize(void)
		{
			HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

			INITIALIZATION_OK("MICRO SERVO");
		}
	}
}
