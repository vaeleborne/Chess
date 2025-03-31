#ifndef CHESS_COLOR_DEFINES_HPP
#define CHESS_COLOR_DEFINES_HPP
#include "Colorful_IO.hpp"
#include <string>
namespace Chess::Colors
{
	inline const std::string PROMPT_COLOR = ColorfulIO::Colors::Foreground::HI_GREEN;
	inline const std::string INVALID_INPUT = ColorfulIO::Colors::Foreground::HI_RED;
	inline const std::string ERROR = ColorfulIO::Colors::Foreground::BOLD_RED;
}



#endif