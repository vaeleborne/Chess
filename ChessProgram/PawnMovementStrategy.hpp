#ifndef PAWN_MOVEMENT_STRATEGY_HPP
#define PAWN_MOVEMENT_STRATEGY_HPP
#include "IMovementStrategy.hpp"
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
	private:
		bool _hasMoved;
		//For checking if the pawn has moved and also setting that value to true (but not back to false)
		bool HasMoved() { return _hasMoved; }
		bool MarkMoved() { _hasMoved = true; }

	public:
		PawnMovementStrategy() {}

	};
}
#endif