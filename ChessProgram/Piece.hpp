#ifndef PIECE_HPP
#define PIECE_HPP
/**
 * @file    Piece.hpp
 * @author  Dylan Morgan
 * @brief   Defines the abstract class for Piece 
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the Piece abstract class.
 *
 */

#include "Position.hpp"
#include <vector>
#include <map>

namespace Chess
{
	class Board; //Forward declaration

	class Piece
	{
	public: 
		enum class Color {WHITE, BLACK, NONE};
	protected:
		Color color;

	public:
		Piece(Color c) : color(c){}

		virtual ~Piece() = default;

		Color GetColor() const { return color; }

		//Pure virtuals
		virtual std::vector<std::pair<int, int>> GetLegalMoves(const Position& position, const Board& board) const = 0;
		virtual char GetSymbol() const = 0;
	};
}

#endif