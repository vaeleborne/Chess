#ifndef KNIGHT_MOVEMENT_STRATEGY_HPP
#define KNIGHT_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"
#include <array>
/**
 * @file    KnightMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a knight piece can make
 * @date    2025-03-24
 * @version 1.0
 * @copyright MIT License
 */


namespace Chess::Pieces
{
	class KnightMovementStrategy : public IMovementStrategy
	{
	private:
		const static std::vector<std::pair<int, int>> _OFFSETS;
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& position, const Chess::Board& board, const Color& color) const override;
	};
}

#endif