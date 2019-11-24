// #include <fosl/math/matrix.h>
#include <fosl/math/vector.h>

#include "drivers.h"

using namespace fosl;
using namespace fosl::math;

using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace fosl::Tty;

		// Matrix<float, 2, 2> m =
		// {
		// 	{ 0.0, 0.1 },
		// 	{ 1.0, 1.1 },
		// };
		// m[0][0] = 0.0;
		// m[0][1] = 0.1;
		// m[1][0] = 1.0;
		// m[1][1] = 1.1;
		// printf("%f\n", m[0][0]);
		// printf("%f\n", m[0][1]);
		// printf("%f\n", m[1][0]);
		// printf("%f\n", m[1][1]);

		puts("v = [ 0.0, 1.0, 2.0 ]");
		putchar('\n');

		Vector<float, 3> v =
		{{
			 0.0,
			 1.0,
			 2.0,
		 }};
		printf("%f\n", v[0]);
		printf("%f\n", v[1]);
		printf("%f\n", v[2]);
		putchar('\n');

		puts("v = -v");
		v = -v;
		printf("%f\n", v[0]);
		printf("%f\n", v[1]);
		printf("%f\n", v[2]);
		putchar('\n');

		while (true) { }
	}
}
