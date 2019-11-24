#include "drivers.h"

using namespace Lib;
using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
	}
}
