#ifndef _EVALUATION_DRIVERS_H_
#define _EVALUATION_DRIVERS_H_

#include "driver/all.h"

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
