#ifndef PAWN_HPP
#define PAWN_HPP
/**
 * @file    Pawn.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Pawn which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Pawn class.
 */

#include "Piece.hpp"
#include "UTF_Pieces.hpp"

namespace Chess::Pieces
{
	class Pawn : public Piece
	{
	public:
		Pawn(Color c) :Piece(c) {}

		virtual ~Pawn() {}

		Color GetColor() const { return color; }

		//Pure virtuals
		std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const override 
		{
			return std::vector<std::pair<int, int>>();
		}
		std::string GetSymbol() const override
		{
			return PAWN_UTF;
		}
	};
}

#endif