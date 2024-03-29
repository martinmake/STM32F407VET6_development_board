project(pwm_dimmer CXX C ASM)

add_stm_executable(
	NAME ${PROJECT_NAME}
	LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/STM32CubeIDE/STM32F407VETX_FLASH.ld

	./application/application.cpp
	./application/config.h
	./application/driver/all.h
	./application/driver/base.cpp
	./application/driver/base.h
	./application/driver/dimmer/gpio.h
	./application/driver/dimmer/singleton.cpp
	./application/driver/dimmer/singleton.h
	./application/driver/dimmer.h
	./application/drivers.cpp
	./application/drivers.h
	./application/driver/status_leds/gpio.h
	./application/driver/status_leds.h
	./application/driver/status_leds/signal.h
	./application/driver/status_leds/singleton.cpp
	./application/driver/status_leds/singleton.h
	./application/driver/tty.h
	./application/driver/tty/singleton.cpp
	./application/driver/tty/singleton.h
	./Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f407xx.h
	./Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h
	./Drivers/CMSIS/Device/ST/STM32F4xx/Include/system_stm32f4xx.h
	./Drivers/CMSIS/Include/cmsis_armcc.h
	./Drivers/CMSIS/Include/cmsis_armclang.h
	./Drivers/CMSIS/Include/cmsis_compiler.h
	./Drivers/CMSIS/Include/cmsis_gcc.h
	./Drivers/CMSIS/Include/cmsis_iccarm.h
	./Drivers/CMSIS/Include/cmsis_version.h
	./Drivers/CMSIS/Include/core_armv8mbl.h
	./Drivers/CMSIS/Include/core_armv8mml.h
	./Drivers/CMSIS/Include/core_cm0.h
	./Drivers/CMSIS/Include/core_cm0plus.h
	./Drivers/CMSIS/Include/core_cm1.h
	./Drivers/CMSIS/Include/core_cm23.h
	./Drivers/CMSIS/Include/core_cm33.h
	./Drivers/CMSIS/Include/core_cm3.h
	./Drivers/CMSIS/Include/core_cm4.h
	./Drivers/CMSIS/Include/core_cm7.h
	./Drivers/CMSIS/Include/core_sc000.h
	./Drivers/CMSIS/Include/core_sc300.h
	./Drivers/CMSIS/Include/mpu_armv7.h
	./Drivers/CMSIS/Include/mpu_armv8.h
	./Drivers/CMSIS/Include/tz_context.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_adc_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_adc.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_exti.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ramfunc.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h
	./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_usb.h
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
	./Inc/adc.h
	./Inc/gpio.h
	./Inc/main.h
	./Inc/stm32f4xx_hal_conf.h
	./Inc/stm32f4xx_it.h
	./Inc/sys.h
	./Inc/tim.h
	./Inc/usbd_cdc_if.h
	./Inc/usbd_conf.h
	./Inc/usbd_desc.h
	./Inc/usb_device.h
	./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc/usbd_cdc.h
	./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c
	./Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_core.h
	./Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_ctlreq.h
	./Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h
	./Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_ioreq.h
	./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
	./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
	./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
	./Src/adc.c
	./Src/gpio.c
	./Src/main.c
	./Src/stm32f4xx_hal_msp.c
	./Src/stm32f4xx_it.c
	./Src/sys.c
	./Src/system_stm32f4xx.c
	./Src/tim.c
	./Src/usbd_cdc_if.c
	./Src/usbd_conf.c
	./Src/usbd_desc.c
	./Src/usb_device.c
	./STM32CubeIDE/Application/Startup/startup_stm32f407vetx.s
	./STM32CubeIDE/Application/User/syscalls.c
	./STM32CubeIDE/Application/User/sysmem.c
)

target_include_directories(
	${PROJECT_NAME}.elf PRIVATE

	./application
	./Drivers
	./Drivers/CMSIS
	./Drivers/CMSIS/Device
	./Drivers/CMSIS/Device/ST
	./Drivers/CMSIS/Device/ST/STM32F4xx
	./Drivers/CMSIS/Device/ST/STM32F4xx/Include
	./Drivers/CMSIS/Device/ST/STM32F4xx/Source
	./Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates
	./Drivers/CMSIS/Include
	./Drivers/STM32F4xx_HAL_Driver
	./Drivers/STM32F4xx_HAL_Driver/Inc
	./Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
	./Drivers/STM32F4xx_HAL_Driver/Src
	./Inc
	./Middlewares
	./Middlewares/ST
	./Middlewares/ST/STM32_USB_Device_Library
	./Middlewares/ST/STM32_USB_Device_Library/Class
	./Middlewares/ST/STM32_USB_Device_Library/Class/CDC
	./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
	./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src
	./Middlewares/ST/STM32_USB_Device_Library/Core
	./Middlewares/ST/STM32_USB_Device_Library/Core/Inc
	./Middlewares/ST/STM32_USB_Device_Library/Core/Src
	./Src
	./STM32CubeIDE
	./STM32CubeIDE/Application
	./STM32CubeIDE/Application/Startup
	./STM32CubeIDE/Application/User
	./STM32CubeIDE/Drivers
	./STM32CubeIDE/Drivers/CMSIS
	./STM32CubeIDE/Drivers/STM32F4xx_HAL_Driver
	./STM32CubeIDE/Middlewares
	./STM32CubeIDE/Middlewares/USB_Device_Library
)

target_link_libraries(
	${PROJECT_NAME}.elf

	fosl-arm-util
	fosl-tty
)
