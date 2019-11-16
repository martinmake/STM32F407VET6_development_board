#include "tty.h"

namespace Fosl
{
	namespace Tty
	{
		// TODO: IMPLEMENT BASED ON: http://www.termsys.demon.co.uk/vtansi.htm#print

		Base::Base(FILE* initial_stream)
			: stream(initial_stream)
		{
		}

		uint8_t Base::get_device_code(void)
		{
			return 0;
		}
		DEVICE_STATUS Base::get_device_status(void)
		{
			return DEVICE_STATUS::OK;
		}
		CursorPosition Base::get_cursor_position(void)
		{
			return CursorPosition { 0, 0 };
		}

		void Base::set_line_wrap(bool enable)
		{
			switch (enable)
			{
				case true:  printf(ESC"7h");
				case false: printf(ESC"7l");
			}
		}
		void Base::set_cursor_position(CursorPosition new_cursor_position)
		{
		}

		void Base::reset_device(void)
		{
			printf(ESC"c");
		}
		void Base::print_screen(void)
		{
		}
		void Base::print_line(void)
		{
		}
		void Base::shift_cursor(CURSOR::DIRECTION direction, uint16_t magnitude)
		{
		}
		void Base::save_cursor(void)
		{
		} void Base::save_cursor_and_attrs(void)
		{
		}
		void Base::restore_cursor(void)
		{
		}
		void Base::restore_cursor_and_attrs(void)
		{
		}
		void Base::define_key(const char* key, const char* definition)
		{
		}

		Base& Base::operator()(TAB tab)
		{
			return *this;
		}
		Base& Base::operator()(ERASE erase)
		{
			switch (erase)
			{
				case ERASE::TO_END_OF_LINE:
					printf(ESC"[K");
					break;
				case ERASE::FROM_START_OF_LINE:
					printf(ESC"[1K");
					break;
				case ERASE::CURRENT_LINE:
					printf(ESC"[2K");
					break;
				case ERASE::TO_TOP_OF_THE_SCREEN:
					printf(ESC"[J");
					break;
				case ERASE::TO_BOTTOM_OF_THE_SCREEN:
					printf(ESC"[1J");
					break;
				case ERASE::SCREEN:
					printf(ESC"[2J");
					break;
			}

			return *this;
		}
		Base& Base::operator()(PRINT print)
		{
			return *this;
		}
		Base& Base::operator()(SCROLL::DIRECTION direction, uint16_t magnitude)
		{
			return *this;
		}
	}
}
