#ifndef ROOK_HPP
#define ROOK_HPP
/**
 * @file    Rook.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Rook which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Rook class.
 */
#include "Piece.hpp"

namespace Chess::Pieces
{
	class Rook : public Piece
	{
	public:
		Rook(Color c) :Piece(c) {}

		virtual ~Rook() {}

		Color GetColor() const { return color; }

		//Pure virtuals
		std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const override
		{
			return std::vector<std::pair<int, int>>();
		}
		std::string GetSymbol() const override
		{
			return ROOK_UTF;
		}
	};
}
#endif