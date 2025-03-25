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
		const static std::vector<std::pair<int, int>> _OFFSETS; 
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& king) const override;
	};

}

#endif