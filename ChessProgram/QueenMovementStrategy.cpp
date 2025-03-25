#include "QueenMovementStrategy.hpp"
#include "MovementHelpers.hpp"

namespace Chess::Pieces
{
	const std::vector<std::pair<int, int>> QueenMovementStrategy::_DIRECTIONS =
	{
		{
			{0,1},
			{0, -1},
			{1, 0},
			{-1, 0},
			{1, 1},
			{1, -1},
			{-1, -1},
			{-1, 1}
		}
	};
	std::vector<Move> QueenMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& queen) const
	{
		std::vector<Move> moves;
		AddSlidingMoves(moves, from, board, queen, _DIRECTIONS);
		return moves;
	}
}