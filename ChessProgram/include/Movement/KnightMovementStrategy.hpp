#ifndef KNIGHT_MOVEMENT_STRATEGY_HPP
#define KNIGHT_MOVEMENT_STRATEGY_HPP
/**
 * @file    KnightMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a knight piece can make
 * @date    2025-03-24
 * @version 1.0
 * @copyright MIT License
 */
#include "IMovementStrategy.hpp"

namespace Chess::Pieces
{
	class KnightMovementStrategy : public IMovementStrategy
	{
	private:
		const static std::vector<std::pair<int, int>> _OFFSETS;
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& knight) const override;
	};
}

#endif