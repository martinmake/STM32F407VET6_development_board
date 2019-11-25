#include "main.h"

inline void Singleton::chip_select(bool select)
{
	HAL_GPIO_WritePin(
			L3G4200D_CS_GPIO_Port,
			L3G4200D_CS_Pin,
			select
				? GPIO_PIN_RESET
				: GPIO_PIN_SET);
}
