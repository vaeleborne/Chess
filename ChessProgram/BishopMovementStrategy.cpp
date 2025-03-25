#include "BishopMovementStrategy.hpp"
#include "MovementHelpers.hpp"

namespace Chess::Pieces
{
	const std::vector<std::pair<int, int>> BishopMovementStrategy::_DIRECTIONS =
	{
		{
			{1, 1},
			{1, -1},
			{-1, -1},
			{-1, 1}
		}
	};
	std::vector<Move> BishopMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& rook) const
	{
		std::vector<Move> moves;
		AddSlidingMoves(moves, from, board, rook, _DIRECTIONS);

		return moves;
	}
}