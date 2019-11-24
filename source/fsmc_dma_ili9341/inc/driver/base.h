#ifndef _EVALUATION_DRIVER_BASE_H_
#define _EVALUATION_DRIVER_BASE_H_

#include <stm32f4xx_hal.h>

#include <util.h>

#include "config.h"

#ifdef INITIALIZATION_VERBOSE
#define INITIALIZATION_OK(    ...) { tty(INITIALIZATION_FORMAT_OK    ); printf(INITIALIZATION_MESSAGE_OK,     __VA_ARGS__); return BITS::OK;     }
#define INITIALIZATION_FAILED(...) { tty(INITIALIZATION_FORMAT_FAILED); printf(INITIALIZATION_MESSAGE_FAILED, __VA_ARGS__); return BITS::FAILED; }
#else
#define INITIALIZATION_OK(    ...) { return BITS::OK;    }
#define INITIALIZATION_FAILED(...) { return BITS::FAILED; }
#endif

namespace Driver
{
	class Base
	{
		public: // CONSTRUCTORS
			Base(void) = default;
		public: // DESTRUCTOR
			virtual ~Base(void) = default;

		public: // METHODS
			virtual bool initialize(void) = 0;
	};
}

#endif
