#ifndef KING_HPP
#define KING_HPP
#include "Piece.hpp"
/**
 * @file    King.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class King which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete King class.
 */
namespace Chess::Pieces
{
	class King : public Piece
	{
	public:
		King(Color c, std::shared_ptr<IMovementStrategy> moveStrat) :Piece(c, moveStrat) {}

		virtual ~King() {}

		Color GetColor() const { return color; }


		std::string GetSymbol() const override
		{
			return KING_UTF;
		}
	};
}

#endif