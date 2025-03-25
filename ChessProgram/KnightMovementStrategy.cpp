#include "KnightMovementStrategy.hpp"
#include "Board.hpp"

namespace Chess::Pieces
{
	std::vector<Position> KnightMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Color& color) const
	{
		//Should return any valid moves for a Knight Piece
		std::vector<Position> moves;

		//Loop through possible offsets
		for (auto [dx, dy] : _offsets)
		{
			Position to(from.file + dx, from.rank + dy);

			//Make sure the position is within the bounds of the board
			if (to.IsValid())
			{
				auto piece = board.GetPieceAt(to);
				
				//If there is no piece there or it is a piece of a different color, it is a valid move!
				if (!piece || piece->GetColor() != color)
				{
					moves.push_back(to);
				}
			}
		}
		return moves;

	}
}