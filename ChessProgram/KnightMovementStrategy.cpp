#include "KnightMovementStrategy.hpp"
#include "Board.hpp"

namespace Chess::Pieces
{
	const std::vector<std::pair<int, int>> KnightMovementStrategy::_OFFSETS = 
	{ 
		{
			{2,1},		{1, 2}, 
			{-1, 2},	{-2, 1}, 
			{-2, -1},	{-1, -2}, 
			{1, -2},	{2, -1}
		} 
	};

	std::vector<Move> KnightMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& knight) const
	{
		//Should return any valid moves for a Knight Piece
		std::vector<Move> moves;

		AddMovesFromOffsets(moves, from, board, knight, _OFFSETS);
		return moves;

	}
}