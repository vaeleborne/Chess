#include "KingMovementStrategy.hpp"
#include "Board.hpp"

namespace Chess::Pieces
{
	std::vector<Move> KingMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Color& color) const
	{
		
		//Check for general movement options
		//Should return any valid moves for a Knight Piece
		std::vector<Move> moves;

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
					moves.push_back(Move(from, to, SpecialMove::NONE));
				}
				else if (piece->GetColor() != color)
				{
					moves.push_back(Move(from, to, SpecialMove::NONE, piece));	//Move can capture a piece!
				}
			}
		}

		//Check for castling options
		bool white = color == Color::WHITE;
		bool kingMoved = white ? board.state.whiteKingMoved : board.state.blackKingMoved;
		bool kingsideRookMoved = white ? board.state.whiteKingsideRookMoved : board.state.blackKingsideRookMoved;
		bool queensideRookMoved = white ? board.state.whiteQueensideRookMoved : board.state.blackQueensideRookMoved;

		

		if (!kingMoved)
		{
			//Check for kingside castling
			if (!kingsideRookMoved)
			{
				Position kingPlusOne = Position(from.file + 1, from.rank);
				Position kingPlusTwo = Position(from.file + 2, from.rank);
				//Make sure the path to the rook is clear (2 spaces to the right of piece must be empty)
				if(board.GetSquare(kingPlusOne).IsEmpty() && board.GetSquare(kingPlusTwo).IsEmpty())
				{
					//Need to be sure we don't move through check!
					if (!board.IsCheck(from) && !board.IsCheck(kingPlusOne) && !board.IsCheck(kingPlusTwo))
					{
						//We can short castle!
						moves.push_back(Move(from, kingPlusTwo, SpecialMove::KINGSIDE_CASTLE));
					}
				}
			}

			//Check for queenside castling
			if (!queensideRookMoved)
			{
				Position kingMinusOne = Position(from.file - 1, from.rank);
				Position kingMinusTwo = Position(from.file - 2, from.rank);
				Position kingMinusThree = Position(from.file - 3, from.rank);

				//Checking that path is clear
				if (board.GetSquare(kingMinusOne).IsEmpty() && board.GetSquare(kingMinusTwo).IsEmpty() && board.GetSquare(kingMinusThree).IsEmpty())
				{
					//Make sure there wouldn't be a check
					if (!board.IsCheck(from) && !board.IsCheck(kingMinusOne) && !board.IsCheck(kingMinusTwo))
					{
						//We can long castle!
						moves.push_back(Move(from, kingMinusTwo, SpecialMove::QUEENSIDE_CASTLE));
					}
				}
			}
		}
		return moves;
	}
}