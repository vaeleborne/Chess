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
#include "Piece.hpp"
namespace Chess
{
	struct Square
	{
		std::shared_ptr<Piece> piece;

		bool IsEmpty() const  { return !piece; }
		bool IsOccupied() const { return piece != nullptr; }

		Piece::Color GetColor() const { return piece ? piece->GetColor() : Piece::Color::NONE; }
	};
}

#endif