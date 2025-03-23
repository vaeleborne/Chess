#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "Piece.hpp"
/**
 * @file    Queen.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete class Queen which is an implementation of Piece
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the concrete Queen class.
 */
namespace Chess::Pieces
{
	class Queen : public Piece
	{
	public:
		Queen(Color c) :Piece(c) {}

		virtual ~Queen() {}

		Color GetColor() const { return color; }

		//Pure virtuals
		std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const override
		{
			return std::vector<std::pair<int, int>>();
		}
		std::string GetSymbol() const override
		{
			return QUEEN_UTF;
		}
	};
}


#endif