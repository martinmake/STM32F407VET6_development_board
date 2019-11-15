#ifndef _LIB_MATH_UTIL_H_
#define _LIB_MATH_UTIL_H_

#undef MIN
#undef MAX
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

#define  LOW_BYTE(word) ((word) & 0xff)
#define HIGH_BYTE(word) ((word) >> 8)

#endif
