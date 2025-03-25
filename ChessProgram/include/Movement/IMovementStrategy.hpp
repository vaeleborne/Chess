#ifndef MOVEMENT_STRATEGY_HPP
#define MOVEMENT_STRATEGY_HPP
#include "Move.hpp"
#include <vector>
/**
 * @file    IMovementStrategy.hpp
 * @author  Dylan Morgan
 * @brief   Defines the interface IMovementStrategy which is to be used by Pieces for their movements
 * @date    2025-03-23
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess { class Board; }
namespace Chess::Pieces
{
	class Piece;
	enum class Color;
	class IMovementStrategy
	{
	public:
		virtual std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& piece) const = 0;
		~IMovementStrategy() = default;
	};
}


#endif