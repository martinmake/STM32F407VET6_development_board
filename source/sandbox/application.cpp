#include "stm32f4xx_hal.h"
#include "main.h"

#define TOGGLE_PIN(pin_name) HAL_GPIO_TogglePin(pin_name##_GPIO_Port, pin_name##_Pin)
#define DELAY(ms) HAL_Delay(ms)

class Blinker
{
	public:
		Blinker& operator()(void)
		{
			TOGGLE_PIN(WARNING_LED);
			TOGGLE_PIN(ERROR_LED);
			DELAY(500);

			return *this;
		}
};

static Blinker blinker;

extern "C" int application(void)
{
	while (true)
	{
		blinker();
	}
}
