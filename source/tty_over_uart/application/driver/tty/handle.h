#ifndef _EVALUATION_DRIVER_TTY_HANDLE_H_
#define _EVALUATION_DRIVER_TTY_HANDLE_H_

#include <fosl/tty/base.h>

#include "driver/base.h"

namespace Driver
{
	namespace Tty
	{
		class Handle : public Base, public fosl::Tty::Base
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
