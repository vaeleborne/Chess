#include "Board.hpp"

namespace Chess
{
	Board::Board()
	{
		//Initialize board to be empty (all null squares)
		squares = std::array<std::array<Square, 8>, 8>();
		for (unsigned int rank = 7; rank > 0; rank--)
		{
			for (unsigned int file = 0; file < 8; file++)
			{
				squares[rank][file].piece = nullptr;
			}
		}

		//Used as the order of the back rank for both players
		std::array<Pieces::PieceType, 8> backRankOrder = {
			Pieces::PieceType::ROOK,
			Pieces::PieceType::KNIGHT,
			Pieces::PieceType::BISHOP,
			Pieces::PieceType::QUEEN,
			Pieces::PieceType::KING,
			Pieces::PieceType::BISHOP,
			Pieces::PieceType::KNIGHT,
			Pieces::PieceType::ROOK
		};

		//We loop twice (once for white and once for black) within we use i = 0 as white else it's black
		for (int i = 0; i < 2; i++)
		{
			//Set the color to white or black appropriately
			Pieces::Color color = (i == 0) ? Pieces::Color::WHITE : Pieces::Color::BLACK;

			int backRank = (i == 0) ? 0 : 7;

			for (int file = 0; file < 8; file++)
			{
				squares[backRank][file].piece = Pieces::PieceFactory::CreatePiece(backRankOrder[file], color);
				int frontRank = (backRank == 0) ? 1 : 6;
				squares[frontRank][file].piece = Pieces::PieceFactory::CreatePiece(Pieces::PieceType::PAWN, color);
			}
		}
	}

	Board::~Board()
	{
	}

	void Board::Print()
	{
		for (int rank = 7; rank >= 0; rank--)
		{
			std::stringstream stream;
			stream << (rank+1);
			ColorfulIO::Write(std::cout, stream.str() + " ", false, true, ColorfulIO::Colors::Foreground::RED);

			for (unsigned int file = 0; file < 8; file++)
			{
				squares[rank][file].PrintSquare(rank % 2 != file % 2); 
				ColorfulIO::Write(std::cout, " ");
			}
			ColorfulIO::WriteNewLines();
		}
		ColorfulIO::Write(std::cout, "  a b c d e f g h", true, true, ColorfulIO::Colors::Foreground::RED);
	}

	std::shared_ptr<Pieces::Piece> Board::GetPieceAt(const Position& pos) const
	{
		//TODO: IMPLEMENT
		throw "NOT IMPLEMENTED";
	}
	void Board::MovePiece(std::shared_ptr<Pieces::Piece> piece, Position& from, Position& to)
	{
		//TODO: IMPLEMENT
		throw "NOT IMPLEMENTED";
	}
}

