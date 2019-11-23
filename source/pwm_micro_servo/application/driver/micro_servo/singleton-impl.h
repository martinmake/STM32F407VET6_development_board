#include "tim.h"

inline void Singleton::set_pulse_width(uint16_t new_pulse_width)
{
	htim4.Instance->CCR1 = new_pulse_width;
}
