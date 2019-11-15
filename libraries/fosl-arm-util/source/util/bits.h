#ifndef _FOSL_UTIL_BITS_H_
#define _FOSL_UTIL_BITS_H_

#define BIT(index) (1 << index)

#define SET(   value, index) value |=  BIT(index)
#define CLEAR( value, index) value &= ~BIT(index)
#define TOOGLE(value, index) value ^=  BIT(index)

#define IS_SET(  value, index) (  value & BIT(index) )
#define IS_CLEAR(value, index) (!(value & BIT(index)))

#define BIN =  2,
#define OCT =  8,
#define DEC = 10,
#define HEX = 16,

namespace BITS
{
	inline const bool ON  = true;
	inline const bool OFF = false;

	inline const bool ENABLE  = true;
	inline const bool DISABLE = false;

	inline const bool OK     = true;
	inline const bool FAILED = false;

	inline const bool HIGH = true;
	inline const bool LOW  = false;

	inline const bool ACK  = true;
	inline const bool NACK = false;
}

#endif
