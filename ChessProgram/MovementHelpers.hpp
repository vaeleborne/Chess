#ifndef MOVEMENT_HELPERS_HPP
#define MOVEMENT_HELPERS_HPP
/**
 * @file    MovementHeklpers.hpp
 * @author  Dylan Morgan
 * @brief   Defines some helper functions for movement, useful to have here outside of other possible dependency conflicts that arise if we make some of these
 *				part of an abstract
 * @date    2025-03-23
 * @version 1.0
 * @copyright MIT License
 */
#include "Board.hpp"
#include "Position.hpp"
#include "Move.hpp"
#include <vector>

namespace Chess::Pieces
{
	void AddMovesFromOffsets(std::vector<Move>& moves, const Position& from, const Board& board, const Piece& piece, const std::vector<std::pair<int, int>>& offsets);

	void AddSlidingMoves(std::vector<Move>& moves, const Position& from, const Board& board, const Piece& piece, const std::vector<std::pair<int, int>>& directions);
}
#endif