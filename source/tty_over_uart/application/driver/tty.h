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
			public:
				Handle(void);
			public:
				~Handle(void) = default;

			public:
				bool initialize(void) override;
		};
	}

	extern Tty::Handle tty;
}

#endif
