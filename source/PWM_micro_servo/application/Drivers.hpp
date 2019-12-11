#ifndef _DRIVERS_HPP_
#define _DRIVERS_HPP_

#include "Driver/all.hpp"

class Drivers
{
	public: // CONSTRUCTORS
		Drivers(void) = default;
	public: // DESTRUCTOR
		~Drivers(void) = default;

	public: // METHODS
		bool initialize(void);
};

extern Drivers drivers;

#endif
