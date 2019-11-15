#ifndef _LIB_TTY_H_
#define _LIB_TTY_H_

#include <util.h>

#ifndef ESC
#define ESC "\033"
#elif ESC != "\033"
#error SYMBOLIC CONSTANT 'ESC' MUST BE SET TO "\033"!
#endif

namespace Fosl
{
	namespace Tty
	{
		enum class DISPLAY_ATTRIBUTE : uint8_t
		{
			RESET                        =   0,
			NORMAL                       =   0,
			BOLD                         =   1,
			FAINT                        =   2,
			ITALIC                       =   3,
			UNDERLINE                    =   4,
			SLOW_BLINK                   =   5,
			RAPID_BLINK                  =   6,
			REVERSE                      =   7,
			CONCEAL                      =   8,
			CROSSEDOUT                   =   9,
			FRAKTUR                      =  20,
			BOLD_OFF                     =  21,
			DOUBLE_UNDERLINE             =  21,
			NORMAL_COLOR                 =  22,
			NORMAL_INTENSITY             =  22,
			ITALIC_AND_FRAKTUR_OFF       =  23,
			UNDERLINE_OFF                =  24,
			BLINK_OFF                    =  25,
			INVERSE_OFF                  =  27,
			REVEAL                       =  28,
			CROSSEDOUT_OFF               =  29,
			FRAMED                       =  51,
			ENCIRCLED                    =  52,
			OVERLINED                    =  53,
			FRAMED_OFF                   =  54,
			ENCIRCLED_OFF                =  54,
			OVERLINED_OFF                =  55,
			IDEOGRAM_UNDERLINE           =  60,
			IDEOGRAM_DOUBLE_UNDERLINE    =  61,
			IDEOGRAM_OVERLINE            =  62,
			IDEOGRAM_DOUBLE_OVERLINE     =  63,
			IDEOGRAM_STRESS_MARKING      =  64,
			IDEOGRAM_ATTRIBUTES_OFF      =  65,

			PRIMARY_FONT                 =  10,
			DEFAULT_FONT                 =  10,
			ALTERNATE_FONT1              =  11,
			ALTERNATE_FONT2              =  12,
			ALTERNATE_FONT3              =  13,
			ALTERNATE_FONT4              =  14,
			ALTERNATE_FONT5              =  15,
			ALTERNATE_FONT6              =  16,
			ALTERNATE_FONT7              =  17,
			ALTERNATE_FONT8              =  18,
			ALTERNATE_FONT9              =  19,

			RGB                          =   2, // FOLLOW WITH 3 * uint8 (R, G, B)
			NUMBER                       =   5, // FOLLOW WITH uint8
			/* 8bit COLOR LAYOUT
				0X00-0X07:  STANDARD COLORS (SAME AS THE 4-BIT COLOURS)
				0X08-0X0F:  HIGH INTENSITY COLORS
				0X10-0XE7:  6 × 6 × 6 CUBE (216 COLORS): 16 + 36 × R + 6 × G + B (0 ≤ R, G, B ≤ 5)
				0XE8-0XFF:  GRAYSCALE FROM BLACK TO WHITE IN 24 STEPS
			*/

			FG_BLACK                     =  30,
			FG_RED                       =  31,
			FG_GREEN                     =  32,
			FG_YELLOW                    =  33,
			FG_BLUE                      =  34,
			FG_MAGENTA                   =  35,
			FG_CYAN                      =  36,
			FG_WHITE                     =  37,
			FG_BRIGHT_BLACK              =  90,
			FG_BRIGHT_RED                =  91,
			FG_BRIGHT_GREEN              =  92,
			FG_BRIGHT_YELLOW             =  93,
			FG_BRIGHT_BLUE               =  94,
			FG_BRIGHT_MAGENTA            =  95,
			FG_BRIGHT_CYAN               =  96,
			FG_BRIGHT_WHITE              =  97,
			FG_SET_COLOR                 =  38, // FOLLOW WITH "COLOR_NUMBER, n" or "COLOR_RGB, r, g, b"
			FG_DEFAULT                   =  39,

			BG_BLACK                     =  40,
			BG_RED                       =  41,
			BG_GREEN                     =  42,
			BG_YELLOW                    =  43,
			BG_BLUE                      =  44,
			BG_MAGENTA                   =  45,
			BG_CYAN                      =  46,
			BG_WHITE                     =  47,
			BG_BRIGHT_BLACK              = 100,
			BG_BRIGHT_RED                = 101,
			BG_BRIGHT_GREEN              = 102,
			BG_BRIGHT_YELLOW             = 103,
			BG_BRIGHT_BLUE               = 104,
			BG_BRIGHT_MAGENTA            = 105,
			BG_BRIGHT_CYAN               = 106,
			BG_BRIGHT_WHITE              = 107,
			BG_SET_COLOR                 =  48, // FOLLOW WITH "COLOR_NUMBER" or "COLOR_RGB"
			BG_DEFAULT                   =  49,
		};

		enum class DEVICE_STATUS : uint8_t
		{
			OK,
			FAILURE,
		};
		namespace CURSOR
		{
			enum class DIRECTION : uint8_t
			{
				UP,
				DOWN,
				LEFT,
				RIGHT,
			};
		}
		namespace SCROLL
		{
			enum class DIRECTION : uint8_t
			{
				UP,
				DOWN,
			};
		}
		enum class TAB : uint8_t
		{
			SET,
			CLEAR,
			CLEAR_ALL,
		};
		enum class ERASE : uint8_t
		{
			TO_END_OF_LINE,
			FROM_START_OF_LINE,
			CURRENT_LINE,
			TO_TOP_OF_THE_SCREEN,
			TO_BOTTOM_OF_THE_SCREEN,
			SCREEN,
		};
		enum class PRINT : uint8_t
		{
			SCREEN,
			LINE,
			LOG_START,
			LOG_STOP,
		};

		struct CursorPosition { uint16_t x, y; };

		class Base
		{
			public:
				Base(FILE* initial_stream);
			public:
				virtual ~Base(void) = default;

			public:
				uint8_t get_device_code(void);
				DEVICE_STATUS get_device_status(void);
				CursorPosition get_cursor_position(void);
			public:
				void set_line_wrap(bool enable);
				void set_cursor_position(CursorPosition new_cursor_position);

			public:
				void reset_device(void);
				void print_screen(void);
				void print_line(void);
				void shift_cursor(CURSOR::DIRECTION direction, uint16_t magnitude);
				void save_cursor(void);
				void save_cursor_and_attrs(void);
				void restore_cursor(void);
				void restore_cursor_and_attrs(void);
				void define_key(const char* key, const char* definition);
				//
				void putchar(int c);
				int  getchar(void);
				void  puts(const char* s);
				char* gets(      char* s, int size);
				int printf(const char* format, ...);
				int scanf (const char* format, ...);

			public:
				template <typename ... Args>
				Base& operator()(Args ... args);
				Base& operator()(TAB tab);
				Base& operator()(ERASE erase);
				Base& operator()(PRINT print);
				Base& operator()(SCROLL::DIRECTION direction, uint16_t magnitude);

			private:
				template <typename Arg, typename ... Args>
				void send_display_attributes(Arg arg, Args ... args);
				template <typename Arg>
				void send_display_attributes(Arg arg);

			private:
				FILE* stream;
		};

		template <typename ... Args>
		Base& Base::operator()(Args ... args)
		{
			printf(ESC"[");
			send_display_attributes(args ...);
			printf("m");

			return *this;
		}

		inline void Base::putchar(int c)
		{
			putc(c, stream);
		}
		inline int Base::getchar(void)
		{
			return getc(stream);
		}
		inline void Base::puts(const char* s)
		{
			fputs(s, stream);
			putc('\n', stream);
		}
		inline char* Base::gets(char* s, int size)
		{
			return fgets(s, size, stream);
		}
		inline int Base::printf(const char* format, ...)
		{
			va_list ap;
			va_start(ap, format);
			return vfprintf(stream, format, ap);
			va_end(ap);
		}
		inline int Base::scanf(const char* format, ...)
		{
			va_list ap;
			va_start(ap, format);
			return vfprintf(stream, format, ap);
			va_end(ap);
		}

		template <typename Arg, typename ... Args>
		void Base::send_display_attributes(Arg arg, Args ... args)
		{
			printf("%u;", static_cast<uint8_t>(arg));
			send_display_attributes(args ...);
		}
		template <typename Arg>
		void Base::send_display_attributes(Arg arg)
		{
			printf("%u", static_cast<uint8_t>(arg));
		}
	}
}

#endif
