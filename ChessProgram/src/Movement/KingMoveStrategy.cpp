#include "../../include/Movement/KingMovementStrategy.hpp"
#include "../../include/Board/Board.hpp"

namespace Chess::Pieces
{
	//Defining our const static var to hold the offsets for the king piece
	const std::vector<std::pair<int, int>> KingMovementStrategy::_OFFSETS = 
	{
		{
			{0,1},
			{0, -1}, 
			{1, 0},		
			{-1, 0}, 
			{1, 1},	
			{1, -1},
			{-1, -1},	
			{-1, 1}
		}
	};

	std::vector<Move> KingMovementStrategy::GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& king) const
	{	
		//Our return vector
		std::vector<Move> moves;

		//Check for common valid moves based on the kings offsets
		AddMovesFromOffsets(moves, from, board, king, _OFFSETS);

		//Getting color to help check for castling universally
		bool white = king.GetColor() == Color::WHITE;
		bool kingMoved = white ? board.state.whiteKingMoved : board.state.blackKingMoved;
		

		
		//If the king has not yet moved, it may be able to castle
		if (!kingMoved)
		{
			//Check for both kingside and queenside rooks to see if they have moved so we can check possible castling moves
			bool kingsideRookMoved = white ? board.state.whiteKingsideRookMoved : board.state.blackKingsideRookMoved;
			bool queensideRookMoved = white ? board.state.whiteQueensideRookMoved : board.state.blackQueensideRookMoved;


			//Check for kingside castling
			if (!kingsideRookMoved)
			{
				//Getting the positions between the king and the kingside rook as we need to do a couple of checks with them
				Position kingPlusOne = Position(from.file + 1, from.rank);
				Position kingPlusTwo = Position(from.file + 2, from.rank);

				//Make sure the path to the rook is clear (2 spaces to the right of piece must be empty for king side, the 3rd space is the rook)
				if(board.GetSquare(kingPlusOne).IsEmpty() && board.GetSquare(kingPlusTwo).IsEmpty())
				{
					//Need to be sure we don't move through a check!
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
				//Getting the positions between the king and the queenside rook to perform checks with
				Position kingMinusOne = Position(from.file - 1, from.rank);
				Position kingMinusTwo = Position(from.file - 2, from.rank);
				Position kingMinusThree = Position(from.file - 3, from.rank);

				//Checking that path is clear, there are 3 spaces between the king and the queenside rook
				if (board.GetSquare(kingMinusOne).IsEmpty() && board.GetSquare(kingMinusTwo).IsEmpty() && board.GetSquare(kingMinusThree).IsEmpty())
				{
					//Make sure there wouldn't be a check (king will only move 2 spaces, no need to test for a check on the 3rd space)
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