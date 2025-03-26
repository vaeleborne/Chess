#ifndef PAWN_HPP
#define PAWN_HPP
/**
 * @file    Pawn.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Pawn which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Pawn class.
 */

#include "Piece.hpp"
#include "UTF_Pieces.hpp"

namespace Chess::Pieces
{
	class Pawn : public Piece
	{
	private:
		bool _hasMoved;
	public:
		Pawn(Color c, std::shared_ptr<IMovementStrategy> moveStrat) :Piece(c, moveStrat), _hasMoved(false) {}

		virtual ~Pawn() {}

		Color GetColor() const { return color; }
		//For checking if the pawn has moved and also setting that value to true (but not back to false)
		bool HasMoved() const { return _hasMoved; }
		bool MarkAsMoved() { _hasMoved = true; }

		std::string GetSymbol() const override
		{
			return PAWN_UTF;
		}
	};
}

#endif