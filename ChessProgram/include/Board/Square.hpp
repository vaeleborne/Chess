#ifndef SQUARE_HPP
#define SQUARE_HPP
/**
 * @file    Square.hpp
 * @author  Dylan Morgan
 * @brief   Defines the struct for a square
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the square struct, this will hold a shared pointer to a piece which could 
 * be null if there is none on the square, it also holds the color of the square, needed for drawing to the terminal
 *
 */
#include <memory>
#include "Colorful_IO.hpp"
#include "../Pieces/Piece.hpp"


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