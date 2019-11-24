#ifndef _EVALUATION_CONFIG_H_
#define _EVALUATION_CONFIG_H_

#include <util.h>
using namespace BITS;

// # STATUS LEDS #
#define STATUS_LED_ERROR_GPIO     GPIOA
#define STATUS_LED_ERROR_GPIO_PIN GPIO_PIN_6
#define STATUS_LED_ERROR_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define STATUS_LED_WARNING_GPIO     GPIOA
#define STATUS_LED_WARNING_GPIO_PIN GPIO_PIN_7
#define STATUS_LED_WARNING_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

// # DISPLAY #
// TODO

// # INITIALIZATION #
#define INITIALIZATION_VERBOSE
#define INITIALIZATION_FORMAT_OK     Lib::TTY::DISPLAY_ATTRIBUTE::FG_GREEN
#define INITIALIZATION_FORMAT_FAILED Lib::TTY::DISPLAY_ATTRIBUTE::FG_RED, Lib::TTY::DISPLAY_ATTRIBUTE::BOLD
#define INITIALIZATION_MESSAGE_OK     "[+] INITIALIZED DRIVER FOR %s!\n"
#define INITIALIZATION_MESSAGE_FAILED "[-] UNABLE TO INITIALIZE DRIVER FOR %s: %s!\n"

#endif

