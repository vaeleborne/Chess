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
#include <array>
#include <Colorful_IO.hpp>
#include "Square.hpp"
#include "../Pieces/PieceFactory.hpp"
#include "../Pieces/Piece.hpp"

namespace Chess
{
	struct BoardState {
		bool whiteKingMoved = false;
		bool blackKingMoved = false;
		bool whiteKingsideRookMoved = false;
		bool blackKingsideRookMoved = false;
		bool whiteQueensideRookMoved = false;
		bool blackQueensideRookMoved = false;
		std::optional<Position> enPassantTarget;
	};



	class Board
	{
	private: 
		std::array<std::array<Square, 8>, 8> squares;

	public: 
		Board();
		~Board();
		BoardState state;
		void Initialize();

		//TODO: IMPLEMENT
		bool IsCheck(const Position& p) const { return false; }

		Square GetSquare(const Position& p) const { return squares[p.file][p.rank]; } 

		std::shared_ptr<Pieces::Piece> GetPieceAt(const Position& pos) const;
		void MovePiece(std::shared_ptr<Pieces::Piece> piece, Position& from, Position& to);

		void Print();
	};

}


#endif