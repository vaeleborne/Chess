#ifndef PIECE_HPP
#define PIECE_HPP
/**
 * @file    Piece.hpp
 * @author  Dylan Morgan
 * @brief   Defines the abstract class for Piece 
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the Piece abstract class.
 *
 */

#include "Position.hpp"
#include "UTF_Pieces.hpp"
#include "IMovementStrategy.hpp"
#include <vector>
#include <map>
#include <memory>

namespace Chess {
	class Board;
}

namespace Chess::Pieces
{
	enum class Color { WHITE, BLACK, NONE };

	class Piece
	{
	public: 
		
	protected:
		Color color;
		std::shared_ptr<IMovementStrategy> movementStrategy;
	public:

		Piece(Color c, std::shared_ptr<IMovementStrategy> moveStrat) : color(c), movementStrategy(moveStrat){}

		virtual ~Piece() = default;

		Color GetColor() const { return color; }

		virtual std::vector<Chess::Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board) const
		{
			return movementStrategy->GetLegalMoves(from, board, this->color);
		}

		virtual std::string  GetSymbol() const = 0;
	};
}

#endif