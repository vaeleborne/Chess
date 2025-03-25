#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "Piece.hpp"
/**
 * @file    Bishop.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Bishop which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Bishop class.
 */
namespace Chess::Pieces
{
	class Bishop : public Piece
	{
	public:
		Bishop(Color c, std::shared_ptr<IMovementStrategy> moveStrat) :Piece(c, moveStrat) {}

		virtual ~Bishop() {}

		Color GetColor() const { return color; }

		
		std::string GetSymbol() const override
		{
			return BISHOP_UTF;
		}
	};
}

#endif