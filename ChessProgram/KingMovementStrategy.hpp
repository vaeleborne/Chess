#ifndef KING_MOVEMENT_STRATEGY_HPP
#define KING_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"
#include <array>
/**
 * @file    KingMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a king piece can make
 * @date    2025-03-24
 * @version 1.0
 * @copyright MIT License
 */


namespace Chess::Pieces
{
	class KingMovementStrategy : public IMovementStrategy
	{
	private:
		std::array<std::pair<int, int>, 8> _offsets = { {
			{0,1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}} };
	public:
		std::vector<Position> GetLegalMoves(const Chess::Position& position, const Chess::Board& board, const Color& color) const override;
	};

}

#endif