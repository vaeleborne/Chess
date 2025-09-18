#include "../../include/Commands/PieceMoveCommand.hpp"

namespace Chess::Commands
{
	void PieceCommand::Execute(Board& board) 
	{
		//Get the piece to move
		std::shared_ptr<Pieces::Piece> current_piece = board.GetPieceAt(_move.from);
		board.MovePiece(current_piece, _move.from, _move.to);

		//Check if there is a captured piece
		//if (_move.capturedPiece != nullptr)
		//{
		//	//TODO: Remove captured piece
		//	board.RemovePiece(_move.to);

		//	//TODO: HANDLE EN PASSANT
		//}
		
		
	}

	void PieceCommand::Undo(Board& board)
	{
		//TODO: Implement
		throw "Not Implemented";
	}

}