#ifndef _DRIVER_TTY_SINGLETON_H_
#define _DRIVER_TTY_SINGLETON_H_

#include <fosl/tty/base.h>

#include "driver/base.h"

namespace Driver
{
	namespace Tty
	{
		class Singleton : public Base, public fosl::Tty::Base
		{
			public:
				Singleton(void);
			public:
				~Singleton(void) = default;

			public:
				bool initialize(void) override;
		};
	}

	extern Tty::Singleton tty;
}

#endif
