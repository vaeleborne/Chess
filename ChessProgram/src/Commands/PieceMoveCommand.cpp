#include "../../include/Commands/PieceMoveCommand.hpp"

namespace Chess::Commands
{
	void PieceCommand::Execute(Board& board) 
	{
		//Get the piece to move
		std::shared_ptr<Pieces::Piece> current_piece = board.GetPieceAt(_move.from);
		board.MovePiece(current_piece, _move.from, _move.to);
		
		if (_move.capturedPiece != nullptr)
		{
			if (board.state.enPassantTarget.has_value() && abs((int)_move.from.file) - (board.state.enPassantTarget.value().file))
			{
				board.RemovePiece(board.state.enPassantTarget.value());
			}
			else
			{
				board.RemovePiece(_move.to);
			}
		}	
	}

	void PieceCommand::Undo(Board& board)
	{
		//TODO: Implement
		throw "Not Implemented";
	}

}