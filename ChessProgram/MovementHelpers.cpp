#include "MovementHelpers.hpp";

void AddOffsetMoveIfValid(std::vector<Chess::Move>& moves, const Chess::Position& from, const Chess::Board& board, const Chess::Pieces::Color& color, int dx, int dy)
{
	Chess::Position to(from.file + dx, from.rank + dy);

	//Make sure the position is within the bounds of the board
	if (to.IsValid())
	{
		auto piece = board.GetPieceAt(to);

		//If there is no piece there or it is a piece of a different color, it is a valid move!
		if (!piece || piece->GetColor() != color)
		{
			moves.push_back(Chess::Move(from, to, Chess::SpecialMove::NONE));
		}
		else if (piece->GetColor() != color)
		{
			moves.push_back(Chess::Move(from, to, Chess::SpecialMove::NONE, piece));	//Move can capture a piece!
		}
	}
}

void  Chess::Pieces::AddMovesFromOffsets(std::vector<Move>& moves, const Position& from, const Board& board, const Color& color, const std::vector<std::pair<int, int>>& offsets)
{
	for (const auto& [dx, dy] : offsets)
	{
		AddOffsetMoveIfValid(moves, from, board, color, dx, dy);
	}
}