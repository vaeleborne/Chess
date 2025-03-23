#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "Piece.hpp"
/**
 * @file    Knight.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Knight which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Knight class.
 */
namespace Chess::Pieces
{
	class Knight : public Piece
	{
	public:
		Knight(Color c) :Piece(c) {}

		virtual ~Knight() {}

		Color GetColor() const { return color; }

		//Pure virtuals
		std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const override
		{
			return std::vector<std::pair<int, int>>();
		}
		std::string GetSymbol() const override
		{
			return KNIGHT_UTF;
		}
	};
}
#endif