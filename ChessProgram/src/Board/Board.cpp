#include "../../include/Board/Board.hpp"

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

	void Board::RemovePiece(const Position& pos)
	{
		//Ensure spot exist
		if (squares.size() >= pos.rank && squares[pos.rank].size() >= pos.file)
		{
			//Change the piece to null
			squares[pos.rank][pos.file].piece = nullptr;
		}
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

	Square Board::GetSquare(const Position& p) const
	{
		return squares[p.rank][p.file];
	}

	std::shared_ptr<Pieces::Piece> Board::GetPieceAt(const Position& pos) const
	{
		return GetSquare(pos).piece;
	}

	void Board::MovePiece(std::shared_ptr<Pieces::Piece> piece, Position& from, Position& to)
	{
		//Ensures the enPassant target is only valid for one turn
		if (state.enPassantTarget.has_value() && piece->GetColor() == GetPieceAt(state.enPassantTarget.value())->GetColor())
		{
			state.enPassantTarget.reset();
		}

		if (squares.size() >= to.rank && squares[to.rank].size() >= to.file)
		{
			squares[to.rank][to.file].piece = piece;
			//TODO: Set piece as has moved!

			if (piece->GetSymbol() == Pieces::PAWN_UTF)
			{
				if (std::dynamic_pointer_cast<Pieces::Pawn>(piece)->HasMoved() == false)
				{
					state.enPassantTarget = to;
					std::dynamic_pointer_cast<Pieces::Pawn>(piece)->MarkAsMoved();
				}
			}

			squares[from.rank][from.file].piece = nullptr;
		}

	}


	bool Board::CanCastleKingside(const Pieces::Color& color) const
	{
		//Getting color to help check for castling universally
		bool white = color == Pieces::Color::WHITE;
		bool kingMoved = white ? state.whiteKingMoved : state.blackKingMoved;


		//If the king has not yet moved, it may be able to castle
		if (!kingMoved)
		{
			//Check for both kingside and queenside rooks to see if they have moved so we can check possible castling moves
			bool kingsideRookMoved = white ? state.whiteKingsideRookMoved : state.blackKingsideRookMoved;
			Position from = white ? Position::FromAlgebraic("e1") : Position::FromAlgebraic("e8");

			//Check for kingside castling
			if (!kingsideRookMoved)
			{
				//Getting the positions between the king and the kingside rook as we need to do a couple of checks with them
				Position kingPlusOne = Position(from.file + 1, from.rank);
				Position kingPlusTwo = Position(from.file + 2, from.rank);

				//Make sure the path to the rook is clear (2 spaces to the right of piece must be empty for king side, the 3rd space is the rook)
				if (this->GetSquare(kingPlusOne).IsEmpty() && this->GetSquare(kingPlusTwo).IsEmpty())
				{
					//Need to be sure we don't move through a check!
					if (!this->IsCheck(from) && !this->IsCheck(kingPlusOne) && !this->IsCheck(kingPlusTwo))
					{
						//We can short castle!
						return true;
					}
				}
			}
		}

		return false;
	}

	bool Board::CanCastleQueenside(const Pieces::Color& color) const
	{
		//Getting color to help check for castling universally
		bool white = color == Pieces::Color::WHITE;
		bool kingMoved = white ? state.whiteKingMoved : state.blackKingMoved;


		//If the king has not yet moved, it may be able to castle
		if (!kingMoved)
		{
			//Check for both kingside and queenside rooks to see if they have moved so we can check possible castling moves
			bool queensideRookMoved = white ? state.whiteQueensideRookMoved : state.blackQueensideRookMoved;
			Position from = white ? Position::FromAlgebraic("e1") : Position::FromAlgebraic("e8");
			//Check for queenside castling
			if (!queensideRookMoved)
			{
				//Getting the positions between the king and the queenside rook to perform checks with
				Position kingMinusOne = Position(from.file - 1, from.rank);
				Position kingMinusTwo = Position(from.file - 2, from.rank);
				Position kingMinusThree = Position(from.file - 3, from.rank);

				//Checking that path is clear, there are 3 spaces between the king and the queenside rook
				if (this->GetSquare(kingMinusOne).IsEmpty() && this->GetSquare(kingMinusTwo).IsEmpty() && this->GetSquare(kingMinusThree).IsEmpty())
				{
					//Make sure there wouldn't be a check (king will only move 2 spaces, no need to test for a check on the 3rd space)
					if (!this->IsCheck(from) && !this->IsCheck(kingMinusOne) && !this->IsCheck(kingMinusTwo))
					{
						//We can long castle!
						return true;
					}
				}
			}
		}
		return false;
	}

}

