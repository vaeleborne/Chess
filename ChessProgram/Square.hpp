#ifndef SQUARE_HPP
#define SQUARE_HPP
/**
 * @file    Piece.hpp
 * @author  Dylan Morgan
 * @brief   Defines the struct for a square
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the square struct, this will effectively be an
 * 8x8 array of Position pointers, if a pointer is null then the position is "empty" this struct will allow
 * for easier testing of legal moves as it can also denote white and black squares and be used to track threatened squares.
 *
 */
#include <memory>
#include "Colorful_IO.hpp"
#include "Piece.hpp"

namespace Chess
{
	struct Square
	{
		std::shared_ptr<Pieces::Piece> piece;

		bool IsEmpty() const  { return !piece; }
		bool IsOccupied() const { return piece != nullptr; }

		Pieces::Color GetColor() const { return piece ? piece->GetColor() : Pieces::Color::NONE; }

		void PrintSquare(bool whiteIfUnoccupied)
		{
			if (this->IsOccupied())
			{
				std::string color;
				color = this->piece->GetColor() == Pieces::Color::WHITE ? ColorfulIO::Colors::Foreground::HI_WHITE : ColorfulIO::Colors::Foreground::BOLD_BLUE;

				ColorfulIO::Write(std::cout, this->piece->GetSymbol(), false, true, color);
			}
			else
			{
				std::string color;
				color = whiteIfUnoccupied ? ColorfulIO::Colors::Foreground::WHITE : ColorfulIO::Colors::Foreground::MAGENTA;
				ColorfulIO::Write(std::cout, Pieces::SQUARE_UTF, false, true, color);
			}
		}
	};
}

#endif