#include "../../include/Movement/PawnMovementStrategy.hpp"
#include "../../include/Board/Board.hpp"

namespace Chess::Pieces
{
	//Helper to see if the pawn can promote
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

	//Helper to add a move for the pawn and mark as a promote move if applicable
	void CheckPromoteAndAddMove(std::vector<Move>& moves, const Chess::Position& from, const Chess::Position& to, const Chess::Board& board, const Piece& pawn)
	{
		if (CanPromote(pawn, to))
		{
			moves.push_back(Move(from, to, SpecialMove::PROMOTION, board.GetPieceAt(to)));
		}
		else
		{
			moves.push_back(Move(from, to, SpecialMove::NONE, board.GetPieceAt(to)));
		}
	}

	void AddCaptureMove(std::vector<Move>& moves, const Chess::Position& from, const Chess::Position& to, const Chess::Board& board, const Piece& activePawn, const std::shared_ptr<Piece> target)
	{
		if (CanPromote(activePawn, to))
		{
			moves.push_back(Move(from, to, SpecialMove::PROMOTION, target));
		}
		else
		{
			moves.push_back(Move(from, to, SpecialMove::NONE, target));
		}
	}
	
	//Checks if the pawn can move diagonally and adds the move if it can
	void CheckAndAddDiagonalMove(std::vector<Move>& moves, const Chess::Position& from, const Chess::Position& diagonal, const Chess::Board& board, const Piece& pawn)
	{
		if (diagonal.IsValid())
		{
			std::shared_ptr<Piece> target = board.GetPieceAt(diagonal);
			if (!board.GetSquare(diagonal).IsEmpty() && target->GetColor() != pawn.GetColor())
			{
				AddCaptureMove(moves, from, diagonal, board, pawn, target);
			}
		}
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
			CheckPromoteAndAddMove(moves, from, forwardOne, board, *thisPawn);
		}
	
		//Check for ability to move two spaces
		if (!thisPawn->HasMoved())
		{
			std::pair<int, int> moveTwo = white ? std::pair<int,int>(0,2) : std::pair<int, int>(0, -2);
			//Check that pawn is not blocked
			Position forwardTwo = Position(from.file, from.rank + moveTwo.second);

			if (forwardOne.IsValid() && forwardTwo.IsValid() && board.GetSquare(forwardOne).IsEmpty() && board.GetSquare(forwardTwo).IsEmpty())
			{
				//Add as a possibility! (this move cannot result in a promotion so no need to check!)
				moves.push_back(Move(from, forwardTwo, SpecialMove::FIRSTPAWNMOVE));
			}
		}

		//Check for diagonal takeover (may also be a promotion!)
		Position leftDiagonal = Position(from.file - 1, forwardOne.rank);
		CheckAndAddDiagonalMove(moves, from, leftDiagonal, board, *thisPawn);

		Position rightDiagonal = Position(from.file + 1, forwardOne.rank);
		CheckAndAddDiagonalMove(moves, from, rightDiagonal, board, *thisPawn);
			

		//Check for en passant
		if (board.state.enPassantTarget.has_value())
		{
			//TODO: Fix LOGIC, 
			auto& epTarget = board.state.enPassantTarget.value();
			if (epTarget.IsValid() && std::abs((int)epTarget.file - (int)from.file) == 1)
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