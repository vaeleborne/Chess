#include "pch.h"
#include "CppUnitTest.h"
#include "../../../ChessProgram/include/Board/Board.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTests
{
	TEST_CLASS(BoardTests)
	{
	public:

		TEST_METHOD(BoardGetSquareReturnsExpectedSquaresAndPieces)
		{
			Chess::Board board;

			//Utf Symbols
			auto sKing = Chess::Pieces::KING_UTF;
			auto sQueen = Chess::Pieces::QUEEN_UTF;
			auto sRook = Chess::Pieces::ROOK_UTF;
			auto sBishop = Chess::Pieces::BISHOP_UTF;
			auto sKnight = Chess::Pieces::KNIGHT_UTF;
			auto sPawn = Chess::Pieces::PAWN_UTF;


			//Check for Kings
			auto whtKing = board.GetSquare(Chess::Position::FromAlgebraic("e1")).piece;
			Assert::IsNotNull(whtKing.get(), L"Expected a piece at e1");
			Assert::AreEqual(sKing, whtKing.get()->GetSymbol(), L"Expected king symbol at e1");

			auto blkKing = board.GetSquare(Chess::Position::FromAlgebraic("e8")).piece;
			Assert::IsNotNull(blkKing.get(), L"Expected a piece at e8");
			Assert::AreEqual(sKing, blkKing.get()->GetSymbol(), L"Expected a king symbol at e8");

			//Check for Queens
			auto whtQueen = board.GetSquare(Chess::Position::FromAlgebraic("d1")).piece;
			Assert::IsNotNull(whtQueen.get(), L"Expected a piece at d1");
			Assert::AreEqual(sQueen, whtQueen.get()->GetSymbol(), L"Expected a queen symbol at d1");

			auto blkQueen = board.GetSquare(Chess::Position::FromAlgebraic("d8")).piece;
			Assert::IsNotNull(blkQueen.get(), L"Expected a piece at d8");
			Assert::AreEqual(sQueen, blkQueen.get()->GetSymbol(), L"Expected a queen symbol at d8");

			//Check for Rooks

			//Check for Bishops

			//Check for Knights


			//Check for pawns
		}
	};
}
