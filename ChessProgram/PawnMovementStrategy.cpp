#include "PawnMovementStrategy.hpp"
#include "Board.hpp"

namespace Chess::Pieces
{
	bool CanPromote(const Piece& pawn, const Position& to)
	{
		if (pawn.GetColor() == Color::WHITE)
		{
			if (to.rank == 7)
				return true;
		}
		else
		{
			if (to.rank == 0)
				return true;
		}
		return false;
	}

	std::vector<Move> PawnMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& pawn) const
	{
		std::vector<Move> moves;

		const Pawn* thisPawn = dynamic_cast<const Pawn*>(&pawn);
		bool white = thisPawn->GetColor() == Color::WHITE;

		std::pair<int, int> moveOne = white ? std::pair<int, int> (0, 1) : std::pair<int, int>(0, -1);

		Position forwardOne = Position(from.file, from.rank + moveOne.second);

		//Basic forward movement
		if (forwardOne.IsValid() && board.GetSquare(forwardOne).IsEmpty())
		{
			if (CanPromote(*thisPawn, forwardOne))
			{
				moves.push_back(Move(from, forwardOne, SpecialMove::PROMOTION));
			}
			else
			{
				moves.push_back(Move(from, forwardOne, SpecialMove::NONE));
			}
		}
	
		//Check for ability to move two spaces
		if (!thisPawn->HasMoved())
		{
			std::pair<int, int> moveTwo = white ? std::pair<int,int>(0,2) : std::pair<int, int>(0, -2);
			//Check that pawn is not blocked
			Position forwardTwo = Position(from.file, from.rank + moveTwo.second);

			if (board.GetSquare(forwardOne).IsEmpty() && board.GetSquare(forwardTwo).IsEmpty())
			{
				//Add as a possibility!
				moves.push_back(Move(from, forwardTwo, SpecialMove::FIRSTPAWNMOVE));
			}
		}

		//Check for diagonal takeover (may also be a promotion!)
		Position leftDiagonal = Position(from.file - 1, forwardOne.rank);
		Position rightDiagonal = Position(from.file + 1, forwardOne.rank);

		if (leftDiagonal.IsValid() && !board.GetSquare(leftDiagonal).IsEmpty() && board.GetPieceAt(leftDiagonal)->GetColor() != thisPawn->GetColor())
		{
			if (CanPromote(*thisPawn, leftDiagonal))
			{
				moves.push_back(Move(from, leftDiagonal, SpecialMove::PROMOTION, board.GetPieceAt(leftDiagonal)));
			}
			else
			{
				moves.push_back(Move(from, leftDiagonal, SpecialMove::NONE, board.GetPieceAt(leftDiagonal)));
			}
		}

		if (rightDiagonal.IsValid() && !board.GetSquare(rightDiagonal).IsEmpty() && board.GetPieceAt(rightDiagonal)->GetColor() != thisPawn->GetColor())
		{
			if (CanPromote(*thisPawn, rightDiagonal))
			{
				moves.push_back(Move(from, rightDiagonal, SpecialMove::PROMOTION, board.GetPieceAt(rightDiagonal)));
			}
			else
			{
				moves.push_back(Move(from, rightDiagonal, SpecialMove::NONE, board.GetPieceAt(rightDiagonal)));
			}
		}

		//Check for en passant
		if (board.state.enPassantTarget.has_value())
		{
			auto epTarget = board.state.enPassantTarget.value();
			if (std::abs((int)epTarget.file - (int)from.file) == 1)
			{
				//enPassantTarget is next to us, now to check if we can go diagonally!
				int offset = white ? 1 : -1;
				Position behindTarget = Position(epTarget.file, epTarget.rank + offset);

				if (board.GetSquare(behindTarget).IsEmpty())
				{
					//We can en passant!
					moves.push_back(Move(from, behindTarget, SpecialMove::EN_PASSANT, board.GetPieceAt(epTarget)));
				}
			}
		}

		return moves;
	}
}