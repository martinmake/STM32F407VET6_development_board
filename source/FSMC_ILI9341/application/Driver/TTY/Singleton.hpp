#ifndef _DRIVER_TTY_SINGLETON_HPP_
#define _DRIVER_TTY_SINGLETON_HPP_

#include <FOSL/TTY/Base.hpp>

#include "Driver/Base.hpp"

namespace Driver
{
	namespace TTY
	{
		class Singleton : public Driver::Base, public FOSL::TTY::Base
		{
			public:
				Singleton(void);
			public:
				~Singleton(void) = default;

			public:
				bool initialize(void) override;
		};
	}

	extern TTY::Singleton tty;
}

#endif
