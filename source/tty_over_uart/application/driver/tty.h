#ifndef _EVALUATION_DRIVER_TTY_H_
#define _EVALUATION_DRIVER_TTY_H_

#include <tty.h>

#include "driver/base.h"

namespace Driver
{
	class Tty : public Base, public Fosl::Tty::Base
	{
		public:
			Tty(void);
		public:
			~Tty(void) = default;

		public:
			bool initialize(void) override;
	};

	extern Tty tty;
}

#endif
