#ifndef MOVE_HPP
#define MOVE_HPP
#include "Piece.hpp"
#include "Position.hpp"
#include <memory>
/**
 * @file    Move.hpp
 * @author  Dylan Morgan
 * @brief   Defines a struct to represent a move, useful for seeing a position from and to, and more importantly, if it is a special move or would take a piece
 * @date    2025-03-23
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess
{
	enum class SpecialMove
	{
		NONE,
		KINGSIDE_CASTLE,
		QUEENSIDE_CASTLE,
		EN_PASSANT,
		PROMOTION
	};

	struct Move
	{
		Position from;
		Position to;
		SpecialMove special;
		std::shared_ptr<Pieces::Piece> capturedPiece = nullptr;

		Move(Position from_, Position to_, SpecialMove special_, std::shared_ptr<Pieces::Piece> capturedPiece_ = nullptr) : from(from_), to(to_), special(special_), capturedPiece(capturedPiece_) {}

	};
}


#endif