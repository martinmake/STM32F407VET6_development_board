#ifndef _APPLICATION_DRIVER_BASE_H_
#define _APPLICATION_DRIVER_BASE_H_

#include <stm32f4xx_hal.h>

#include <fosl/util.h>
using namespace bits;

#define INITIALIZATION_OK(    ...) { return OK;     }
#define INITIALIZATION_FAILED(...) { return FAILED; }

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
