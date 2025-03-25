#include "../../include/Movement/BishopMovementStrategy.hpp"
#include "../../include/Movement/MovementHelpers.hpp"

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
	std::vector<Move> BishopMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& bishop) const
	{
		std::vector<Move> moves;
		AddSlidingMoves(moves, from, board, bishop, _DIRECTIONS);

		return moves;
	}
}