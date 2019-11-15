#ifndef _DRIVER_BASE_H_
#define _DRIVER_BASE_H_

#include <stm32f4xx_hal.h>

#include <util.h>
using namespace BITS;

#define INITIALIZATION_OK(    ...) { return BITS::OK;     }
#define INITIALIZATION_FAILED(...) { return BITS::FAILED; }

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
