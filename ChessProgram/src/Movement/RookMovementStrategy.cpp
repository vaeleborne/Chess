#include "../../include/Movement/RookMovementStrategy.hpp"
#include "../../include/Movement/MovementHelpers.hpp"

namespace Chess::Pieces
{

	const std::vector<std::pair<int, int>> RookMovementStrategy::_DIRECTIONS =
	{
		{
			{0,1},
			{0, -1},
			{1, 0},
			{-1, 0}
		}
	};
	std::vector<Move> RookMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& rook) const
	{
		std::vector<Move> moves;
		AddSlidingMoves(moves, from, board, rook, _DIRECTIONS);	
		return moves;
	}
}