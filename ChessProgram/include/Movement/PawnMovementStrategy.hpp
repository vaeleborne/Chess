#ifndef PAWN_MOVEMENT_STRATEGY_HPP
#define PAWN_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"
#include "../Pieces/Pawn.hpp"
/**
 * @file    PawnMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of the IMovementStrategy interface which is used to get the valid moves a pawn piece can make
 * @date    2025-03-24
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess::Pieces
{
	class PawnMovementStrategy : public IMovementStrategy
	{
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& pawn) const override;

	};
}
#endif