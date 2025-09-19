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
		
		//Handle Castling
		Pieces::Color kingColor = king.GetColor();
		if (board.CanCastleKingside(kingColor))
		{
			Position to = kingColor == Pieces::Color::WHITE ? Position::FromAlgebraic("g1") : Position::FromAlgebraic("g8");
			moves.push_back(Move(from, to, SpecialMove::KINGSIDE_CASTLE));
		}

		if (board.CanCastleQueenside(kingColor))
		{
			Position to = kingColor == Pieces::Color::WHITE ? Position::FromAlgebraic("c1") : Position::FromAlgebraic("c8");
			moves.push_back(Move(from, to, SpecialMove::QUEENSIDE_CASTLE));
		}
		
		return moves;
	}
}