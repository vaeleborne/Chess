#ifndef BOARD_HPP
#define BOARD_HPP
/**
 * @file    Board.hpp
 * @author  Dylan Morgan
 * @brief   Defines the Board for the chess engine.
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the Board class.
 * 
 * TODO: Implement Class!
 */
#include "Colorful_IO.hpp"
#include "Square.hpp"
#include <array>

namespace Chess
{
	class Board
	{
	private: 
		std::array<std::array<Square, 8>, 8> squares;

	public: 
		Board();
		~Board();

		void Initialize();

		std::shared_ptr<Piece> GetPieceAt(const Position& pos) const;
		void MovePiece(std::shared_ptr<Piece> piece, Position& from, Position& to);

		void Print();
	};

}


#endif