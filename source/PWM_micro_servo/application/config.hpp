#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "stm32f4xx_hal.h"
#include "main.h"

#include <FOSL/Utilities.hpp>
using namespace FOSL;
using namespace FOSL::Utilities::Bits;
using namespace FOSL::Math::Utilities;

#define INITIALIZATION_FORMAT_OK     FOSL::TTY::DISPLAY_ATTRIBUTE::FG_GREEN
#define INITIALIZATION_FORMAT_FAILED FOSL::TTY::DISPLAY_ATTRIBUTE::FG_RED, FOSL::TTY::DISPLAY_ATTRIBUTE::BOLD
#define INITIALIZATION_MESSAGE_OK     "[+] INITIALIZED DRIVER FOR %s!\n"
#define INITIALIZATION_MESSAGE_FAILED "[-] UNABLE TO INITIALIZE DRIVER FOR %s: %s!\n"

#endif

