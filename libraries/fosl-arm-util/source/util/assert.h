#ifndef _LIB_UTIL_ASSERT_H_
#define _LIB_UTIL_ASSERT_H_

#include <stdio.h>

extern void assert_failed(const char* exp, const char* file, int line);
#define assert(exp) if (!(exp)) assert_failed(#exp, __FILE__, __LINE__);
#ifndef CUSTOM_ASSERT
inline void assert_failed(const char* exp, const char* file, int line)
{
	fprintf(stderr, "\033[0;91;1m"); // RESET;BRIGHT_RED;BOLD
	fprintf(stderr, "%s:%d: ASSERTION `%s' FAILED! ☠ \n", file, line, exp);

	while(true) { }
}
#endif

#endif
