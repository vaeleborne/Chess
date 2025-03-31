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
#include <memory>
#include <Colorful_IO.hpp>
#include "Square.hpp"
#include "../Pieces/PieceFactory.hpp"
#include "../Pieces/Piece.hpp"

namespace Chess
{
	/// <summary>
	/// Struct which contains important state information about the board
	/// </summary>
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

		/// <summary>
		/// Function to Initialize the board
		/// </summary>
		void Initialize();

		//TODO: IMPLEMENT IsCheck, LIKELY NEED TO ADD PARAMETER FOR ATTACKING COLOR
		
		/// <summary>
		/// Function to check if a given position is a check
		/// </summary>
		/// <param name="p">Position to test</param>
		/// <returns>True if that position would create a check</returns>
		bool IsCheck(const Position& p) const { return false; }

		/// <summary>
		/// Returns a square that is like the one at a given position
		/// </summary>
		Square GetSquare(const Position& p) const { return squares[p.file][p.rank]; } 

		/// <summary>
		/// Returns a shared pointer representing a piece at a given position
		/// </summary>
		std::shared_ptr<Pieces::Piece> GetPieceAt(const Position& pos) const;
		void MovePiece(std::shared_ptr<Pieces::Piece> piece, Position& from, Position& to);

		/// <summary>
		/// Function to check if it is possible for a given color to castle kingside
		/// </summary>
		bool CanCastleKingside(const Pieces::Color& color) const;

		/// <summary>
		/// Function to check if it is possible for a given color to castle queenside
		/// </summary>
		bool CanCastleQueenside(const Pieces::Color& color) const;

		void Print();
	};

}


#endif