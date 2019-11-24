inline void Singleton::chip_select(bool select)
{
	HAL_GPIO_WritePin(L3GD20_CS_GPIO_Port, L3GD20_CS_Pin, select ? GPIO_PIN_SET : GPIO_PIN_SET);
}
