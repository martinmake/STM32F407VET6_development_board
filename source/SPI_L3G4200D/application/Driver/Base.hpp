#ifndef _DRIVER_BASE_HPP_
#define _DRIVER_BASE_HPP_

#include "config.hpp"

#ifdef DEBUG
#define INITIALIZATION_OK(    ...) { tty(INITIALIZATION_FORMAT_OK    ); printf(INITIALIZATION_MESSAGE_OK,     __VA_ARGS__); tty(FOSL::TTY::DISPLAY_ATTRIBUTE::RESET); return OK;     }
#define INITIALIZATION_FAILED(...) { tty(INITIALIZATION_FORMAT_FAILED); printf(INITIALIZATION_MESSAGE_FAILED, __VA_ARGS__); tty(FOSL::TTY::DISPLAY_ATTRIBUTE::RESET); return FAILED; }
#else
#define INITIALIZATION_OK(    ...) { return OK;    }
#define INITIALIZATION_FAILED(...) { return FAILED; }
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
