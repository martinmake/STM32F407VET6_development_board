#include "drivers.h"

#define TTY_RGB_COLOR(r, g, b) \
	tty(DISPLAY_ATTRIBUTE::FG_SET_COLOR, DISPLAY_ATTRIBUTE::RGB, r, g, b);

#define DELAY_TIME 500

using namespace fosl;
using namespace Driver;

extern "C" void application(void)
{
	drivers.initialize();

	while (true)
	{
		using namespace fosl::Tty;

		tty(
			DISPLAY_ATTRIBUTE::RESET,
			DISPLAY_ATTRIBUTE::FG_YELLOW,
			DISPLAY_ATTRIBUTE::BOLD);
		tty.puts(
		R"(
       _           _            _       _           _             _             _       _
      /\ \        /\ \         /\ \    /\ \        /\ \         /\ \           / /\    / /\
     /  \ \____  /  \ \       /  \ \   \_\ \      /  \ \       /  \ \         / / /   / / /
    / /\ \_____\/ /\ \ \     / /\ \ \  /\__ \    / /\ \ \     / /\ \ \       / /_/   / / /
   / / /\/___  / / /\ \_\   / / /\ \_\/ /_ \ \  / / /\ \_\   / / /\ \ \     / /\ \__/ / /
  / / /   / / / /_/_ \/_/  / /_/_ \/_/ / /\ \ \/ /_/_ \/_/  / / /  \ \_\   / /\ \___\/ /
 / / /   / / / /____/\    / /____/\ / / /  \/_/ /____/\    / / /    \/_/  / / /\/___/ /
/ / /   / / / /\____\/   / /\____\// / /     / /\____\/   / / /          / / /   / / /
\ \ \__/ / / / /______  / / /     / / /     / / /______  / / /________  / / /   / / /
 \ \___\/ / / /_______\/ / /     /_/ /     / / /_______\/ / /_________\/ / /   / / /
  \/_____/\/__________/\/_/      \_\/      \/__________/\/____________/\/_/    \/_/
		)");
		HAL_Delay(DELAY_TIME);

		tty(
			DISPLAY_ATTRIBUTE::RESET,
			DISPLAY_ATTRIBUTE::FG_MAGENTA,
			DISPLAY_ATTRIBUTE::BOLD,
			DISPLAY_ATTRIBUTE::RAPID_BLINK);
		tty.puts(
		R"(
    ___      __ _____          _
   /   \___ / _/__   \___  ___| |__
  / /\ / _ \ |_  / /\/ _ \/ __| '_ \
 / /_//  __/  _|/ / |  __/ (__| | | |
/___,' \___|_|  \/   \___|\___|_| |_|
		)");
		HAL_Delay(DELAY_TIME);

		tty(
			DISPLAY_ATTRIBUTE::RESET,
			DISPLAY_ATTRIBUTE::FG_RED);
		tty.puts(
		R"(
▓█████▄ ▓█████   █████▒▄▄▄█████▓▓█████ ▄████▄   ██░ ██
▒██▀ ██▌▓█   ▀ ▓██   ▒ ▓  ██▒ ▓▒▓█   ▀▒██▀ ▀█  ▓██░ ██▒
░██   █▌▒███   ▒████ ░ ▒ ▓██░ ▒░▒███  ▒▓█    ▄ ▒██▀▀██░
░▓█▄   ▌▒▓█  ▄ ░▓█▒  ░ ░ ▓██▓ ░ ▒▓█  ▄▒▓▓▄ ▄██▒░▓█ ░██
░▒████▓ ░▒████▒░▒█░      ▒██▒ ░ ░▒████▒ ▓███▀ ░░▓█▒░██▓
 ▒▒▓  ▒ ░░ ▒░ ░ ▒ ░      ▒ ░░   ░░ ▒░ ░ ░▒ ▒  ░ ▒ ░░▒░▒
 ░ ▒  ▒  ░ ░  ░ ░          ░     ░ ░  ░ ░  ▒    ▒ ░▒░ ░
 ░ ░  ░    ░    ░ ░      ░         ░  ░         ░  ░░ ░
   ░       ░  ░                    ░  ░ ░       ░  ░  ░
 ░                                    ░
		)");
		HAL_Delay(DELAY_TIME);

		tty(
			DISPLAY_ATTRIBUTE::RESET,
			DISPLAY_ATTRIBUTE::SLOW_BLINK,
			DISPLAY_ATTRIBUTE::FG_BLUE);
		tty.puts(
		R"(
██████╗ ███████╗███████╗████████╗███████╗ ██████╗██╗  ██╗
██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔════╝██║  ██║
██║  ██║█████╗  █████╗     ██║   █████╗  ██║     ███████║
██║  ██║██╔══╝  ██╔══╝     ██║   ██╔══╝  ██║     ██╔══██║
██████╔╝███████╗██║        ██║   ███████╗╚██████╗██║  ██║
╚═════╝ ╚══════╝╚═╝        ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝
		)");
		HAL_Delay(DELAY_TIME);

		tty(DISPLAY_ATTRIBUTE::RESET);
		TTY_RGB_COLOR(255,   0,   0); tty.puts(R"(████████▄     ▄████████    ▄████████     ███        ▄████████  ▄████████    ▄█    █▄    )");
		TTY_RGB_COLOR(255, 127,   0); tty.puts(R"(███   ▀███   ███    ███   ███    ███ ▀█████████▄   ███    ███ ███    ███   ███    ███   )");
		TTY_RGB_COLOR(255, 255,   0); tty.puts(R"(███    ███   ███    █▀    ███    █▀     ▀███▀▀██   ███    █▀  ███    █▀    ███    ███   )");
		TTY_RGB_COLOR(  0, 255,   0); tty.puts(R"(███    ███  ▄███▄▄▄      ▄███▄▄▄         ███   ▀  ▄███▄▄▄     ███         ▄███▄▄▄▄███▄▄ )");
		TTY_RGB_COLOR(  0, 255,   0); tty.puts(R"(███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀         ███     ▀▀███▀▀▀     ███        ▀▀███▀▀▀▀███▀  )");
		TTY_RGB_COLOR(  0,   0, 255); tty.puts(R"(███    ███   ███    █▄    ███            ███       ███    █▄  ███    █▄    ███    ███   )");
		TTY_RGB_COLOR( 75,   0, 130); tty.puts(R"(███   ▄███   ███    ███   ███            ███       ███    ███ ███    ███   ███    ███   )");
		TTY_RGB_COLOR(148,   0, 211); tty.puts(R"(████████▀    ██████████   ███           ▄████▀     ██████████ ████████▀    ███    █▀    )");
		HAL_Delay(DELAY_TIME);

		tty(DISPLAY_ATTRIBUTE::RESET);
		tty.putchar('\n');
		TTY_RGB_COLOR(0, 170,  43); tty.puts(R"( ▄▀▀█▄▄   ▄▀▀█▄▄▄▄  ▄▀▀▀█▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄  )");
		TTY_RGB_COLOR(0, 127,  40); tty.puts(R"(█ ▄▀   █ ▐  ▄▀   ▐ █  ▄▀  ▀▄ █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀ )");
		TTY_RGB_COLOR(0, 200,   8); tty.puts(R"(▐ █    █   █▄▄▄▄▄  ▐ █▄▄▄▄   ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█  )");
		TTY_RGB_COLOR(0, 255,  28); tty.puts(R"(  █    █   █    ▌   █    ▐      █        █    ▌    █         █   █  )");
		TTY_RGB_COLOR(0, 230,   0); tty.puts(R"( ▄▀▄▄▄▄▀  ▄▀▄▄▄▄    █         ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀  )");
		TTY_RGB_COLOR(0, 150,  45); tty.puts(R"(█     ▐   █    ▐   █         █          █    ▐   █     ▐   █   █    )");
		TTY_RGB_COLOR(0, 120,  20); tty.puts(R"(▐         ▐        ▐         ▐          ▐        ▐         ▐   ▐    )");
		HAL_Delay(DELAY_TIME);

		tty.putchar('\n');
		assert(false && "LOOP ENDED");
	}
}
