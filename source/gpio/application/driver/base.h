#ifndef _APPLICATION_DRIVER_BASE_H_
#define _APPLICATION_DRIVER_BASE_H_

#include "util.h"

#define INITIALIZATION_OK(    ...) { return OK;     }
#define INITIALIZATION_FAILED(...) { return FAILED; }

namespace Driver
{
	class Base
	{
		protected: // CONSTRUCTORS
			Base(void) = default;
		protected: // DESTRUCTOR
			virtual ~Base(void) = default;

		public: // METHODS
			virtual bool initialize(void) = 0;
	};
}

#endif
