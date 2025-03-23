#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "Piece.hpp"
/**
 * @file    Bishop.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Bishop which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Bishop class.
 */
namespace Chess::Pieces
{
	class Bishop : public Piece
	{
	public:
		Bishop(Color c) :Piece(c) {}

		virtual ~Bishop() {}

		Color GetColor() const { return color; }

		//Pure virtuals
		std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const override
		{
			return std::vector<std::pair<int, int>>();
		}
		std::string GetSymbol() const override
		{
			return BISHOP_UTF;
		}
	};
}

#endif