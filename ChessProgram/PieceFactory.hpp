#ifndef PIECE_FACTORY_HPP
#define PIECE_FACTORY_HPP
/**
 * @file    PieceFactory.hpp
 * @author  Dylan Morgan
 * @brief   Defines a factory pattern to create pieces!
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements a factory for creating pieces.
 */
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include <memory>



namespace Chess::Pieces
{
	enum class PieceType {
		PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
	};
	class PieceFactory
	{
	public: 
		static std::shared_ptr<Piece> CreatePiece(PieceType type, Piece::Color color);
	};
}
#endif