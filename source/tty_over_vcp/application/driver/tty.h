#ifndef _EVALUATION_DRIVER_TTY_H_
#define _EVALUATION_DRIVER_TTY_H_

#include <tty.h>

#include "driver/base.h"

namespace Driver
{
	namespace Tty
	{
		class Handle : public Base, public Fosl::Tty::Base
		{
			public: // CONSTRUCTORS
				Handle(void);
			public: // DESTRUCTOR
				~Handle(void) = default;

			public: // METHODS
				bool initialize(void) override;
		};
	}

	extern Tty::Handle tty;
}

#endif
