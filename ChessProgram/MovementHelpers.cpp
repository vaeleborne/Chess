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

void Chess::Pieces::AddSlidingMobrd(std::vector<Move>& moves, const Position& from, const Board& board, const Color& color, 
	const std::vector<std::pair<int, int>>& directions)
{
	for (const auto& [dx, dy] : directions)
	{
		int curX = from.file + dx;
		int curY = from.rank + dy;

		while (curX >= 0 && curX < 8 && curY >= 0 && curY < 8)
		{
			Position to(curX, curY);
			auto square = board.GetSquare(to);

			if (square.IsEmpty())
			{
				moves.push_back(Move(from, to, SpecialMove::NONE));
			}
			else
			{
				//The square is occupied, check to see if it is one we can capture
				if (square.piece->GetColor() != color)
				{
					moves.push_back(Move(from, to, SpecialMove::NONE, square.piece));
				}
				break; //We can't move past a piece
			}
			curX += dx;
			curY += dy;
		}
	}
}