#ifndef QUEEN_MOVEMENT_STRATEGY_HPP
#define QUEEN_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"

/**
 * @file    QueeMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a queen piece can make
 * @date    2025-03-25
 * @version 1.0
 * @copyright MIT License
 */

namespace Chess::Pieces
{
	class QueenMovementStrategy : public IMovementStrategy
	{
	private:
		static const std::vector<std::pair<int, int>> _DIRECTIONS;
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& queen) const override;
	};
}


#endif