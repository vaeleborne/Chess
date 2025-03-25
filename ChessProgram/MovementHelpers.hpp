#ifndef MOVEMENT_HELPERS_HPP
#define MOVEMENT_HELPERS_HPP
#include "Board.hpp"
#include "Position.hpp"
#include "Move.hpp"
#include <vector>
namespace Chess::Pieces
{
	void AddMovesFromOffsets(std::vector<Move>& moves, const Position& from, const Board& board, const Color& color, const std::vector<std::pair<int, int>>& offsets);
}
#endif