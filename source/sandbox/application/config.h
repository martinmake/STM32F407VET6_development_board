#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "stm32f4xx_hal.h"

#include <fosl/util.h>
using namespace bits;

#define INITIALIZATION_FORMAT_OK     fosl::Tty::DISPLAY_ATTRIBUTE::FG_GREEN
#define INITIALIZATION_FORMAT_FAILED fosl::Tty::DISPLAY_ATTRIBUTE::FG_RED, fosl::Tty::DISPLAY_ATTRIBUTE::BOLD
#define INITIALIZATION_MESSAGE_OK     "[+] INITIALIZED DRIVER FOR %s!\n"
#define INITIALIZATION_MESSAGE_FAILED "[-] UNABLE TO INITIALIZE DRIVER FOR %s: %s!\n"

#endif

