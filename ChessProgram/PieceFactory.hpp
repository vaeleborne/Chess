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
#include "KnightMovementStrategy.hpp"
#include "KingMovementStrategy.hpp"
#include "PawnMovementStrategy.hpp"
#include "RookMovementStrategy.hpp"
#include "BishopMovementStrategy.hpp"







namespace Chess::Pieces
{
	////TODO: REMOVE THE BELOW CLASS FOR GENERICE MOVEMENT, IT IS JUST A PLACEHOLDER UNTIL ACTUAL STRATEGIES GET DEFINED


	class MockMovement : public Chess::Pieces::IMovementStrategy
	{
	public:
		std::vector<Move> GetLegalMoves(const Chess::Position& from, const Chess::Board& board, const Piece& piece) const override
		{
			return std::vector<Move>();
		}
		~MockMovement(){}
	};

	enum class PieceType {
		PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
	};
	class PieceFactory
	{
	public: 
		static std::shared_ptr<Piece> CreatePiece(PieceType type, Color color);
	};
}
#endif