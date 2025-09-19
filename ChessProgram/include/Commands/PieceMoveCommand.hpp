#ifndef PIECE_MOVE_COMMAND
#define PICE_MOVE_COMMAND
#include "../Pieces/Piece.hpp"
#include "../Movement/Move.hpp"
#include "IMoveCommand.hpp"
#include <memory>
/**
 * @file    PieceMoveCommand.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of our IMoveCommand to be used for pieces
 * @date    2025-03-27
 * @version 1.0
 * @copyright MIT License
 */

namespace Chess::Commands {
	class PieceCommand : public IMoveCommand {
	private:
		Move _move;

	public:
		PieceCommand(const Move& move) : _move(move) {}

		void Execute(Board& board) override;

		void Undo(Board& board) override;


	};
}

#endif