#ifndef _EVALUATION_DRIVER_TTY_H_
#define _EVALUATION_DRIVER_TTY_H_

#include <tty.h>

#include "driver/base.h"

namespace Driver
{
	class Tty : public Base, public Lib::Tty::Tty
	{
		public: // CONSTRUCTORS
			Tty(void) = default;
		public: // DESTRUCTOR
			~Tty(void) = default;

		public: // METHODS
			bool initialize(void) override;
	};

	extern Tty tty;
}

#endif
