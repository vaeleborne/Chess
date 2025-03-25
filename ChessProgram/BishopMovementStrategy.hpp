#ifndef BISHOP_MOVEMENT_STRATEGY_HPP
#define BISHOP_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"
/**
 * @file    BishopMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a Bishop piece can make
 * @date    2025-03-25
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess::Pieces
{
	class BishopMovementStrategy : public IMovementStrategy
	{
	private:
		static const std::vector<std::pair<int, int>> _DIRECTIONS;
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& rook) const override;

	};
}
#endif