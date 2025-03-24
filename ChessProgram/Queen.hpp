#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "Piece.hpp"
/**
 * @file    Queen.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Queen which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Queen class.
 */
namespace Chess::Pieces
{
	class Queen : public Piece
	{
	public:
		Queen(Color c, std::shared_ptr<IMovementStrategy> moveStrat) :Piece(c, moveStrat) {}

		virtual ~Queen() {}

		Color GetColor() const { return color; }


		std::string GetSymbol() const override
		{
			return QUEEN_UTF;
		}
	};
}


#endif