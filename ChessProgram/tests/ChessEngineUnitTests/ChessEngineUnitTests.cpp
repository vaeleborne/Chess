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


			//-----------------Checking for Kings-----------------
			//White Kings
			auto whtKing = board.GetSquare(Chess::Position::FromAlgebraic("e1")).piece;
			Assert::IsNotNull(whtKing.get(), L"Expected a piece at e1");
			Assert::AreEqual(sKing, whtKing.get()->GetSymbol(), L"Expected king symbol at e1");

			//Black Kings
			auto blkKing = board.GetSquare(Chess::Position::FromAlgebraic("e8")).piece;
			Assert::IsNotNull(blkKing.get(), L"Expected a piece at e8");
			Assert::AreEqual(sKing, blkKing.get()->GetSymbol(), L"Expected a king symbol at e8");

			//-----------------Checking for Queens-----------------
			//White Queen
			auto whtQueen = board.GetSquare(Chess::Position::FromAlgebraic("d1")).piece;
			Assert::IsNotNull(whtQueen.get(), L"Expected a piece at d1");
			Assert::AreEqual(sQueen, whtQueen.get()->GetSymbol(), L"Expected a queen symbol at d1");

			//Black Queen
			auto blkQueen = board.GetSquare(Chess::Position::FromAlgebraic("d8")).piece;
			Assert::IsNotNull(blkQueen.get(), L"Expected a piece at d8");
			Assert::AreEqual(sQueen, blkQueen.get()->GetSymbol(), L"Expected a queen symbol at d8");

			//-----------------Checking for Rooks-----------------
			//White Rooks
			auto whtRook1 = board.GetSquare(Chess::Position::FromAlgebraic("a1")).piece;
			auto whtRook2 = board.GetSquare(Chess::Position::FromAlgebraic("h1")).piece;
			
			Assert::IsNotNull(whtRook1.get(), L"Expected a piece at a1");
			Assert::IsNotNull(whtRook2.get(), L"Expected a piece at h1");

			Assert::AreEqual(sRook, whtRook1.get()->GetSymbol(), L"Expected a rook symbol at a1");
			Assert::AreEqual(sRook, whtRook2.get()->GetSymbol(), L"Expected a rook symbol at h1");

			//Black Rooks
			auto blkRook1 = board.GetSquare(Chess::Position::FromAlgebraic("a8")).piece;
			auto blkRook2 = board.GetSquare(Chess::Position::FromAlgebraic("h8")).piece;

			Assert::IsNotNull(blkRook1.get(), L"Expected a piece at a1");
			Assert::IsNotNull(blkRook2.get(), L"Expected a piece at h1");

			Assert::AreEqual(sRook, blkRook1.get()->GetSymbol(), L"Expected a rook symbol at a1");
			Assert::AreEqual(sRook, blkRook2.get()->GetSymbol(), L"Expected a rook symbol at h1");


			//-----------------Checking for Knights-----------------
			//White Knights
			auto whtKnight1 = board.GetSquare(Chess::Position::FromAlgebraic("b1")).piece;
			auto whtKnight2 = board.GetSquare(Chess::Position::FromAlgebraic("g1")).piece;

			Assert::IsNotNull(whtKnight1.get(), L"Expected a piece at b1");
			Assert::IsNotNull(whtKnight1.get(), L"Expected a piece at g1");

			Assert::AreEqual(sKnight, whtKnight1.get()->GetSymbol(), L"Expected a knight at b1");
			Assert::AreEqual(sKnight, whtKnight2.get()->GetSymbol(), L"Expected a knight at g1");

			//Black Knights
			auto blkKnight1 = board.GetSquare(Chess::Position::FromAlgebraic("b8")).piece;
			auto blkKnight2 = board.GetSquare(Chess::Position::FromAlgebraic("g8")).piece;

			Assert::IsNotNull(blkKnight1.get(), L"Expected a piece at b1");
			Assert::IsNotNull(blkKnight2.get(), L"Expected a piece at g1");

			Assert::AreEqual(sKnight, blkKnight1.get()->GetSymbol(), L"Expected a knight at b1");
			Assert::AreEqual(sKnight, blkKnight2.get()->GetSymbol(), L"Expected a knight at g1");

			//-----------------Checking for Bishops-----------------
			//White Bishops
			auto whtBishop1 = board.GetSquare(Chess::Position::FromAlgebraic("c1")).piece;
			auto whtBishop2 = board.GetSquare(Chess::Position::FromAlgebraic("f1")).piece;

			Assert::IsNotNull(whtBishop1.get(), L"Expected a piece at c1");
			Assert::IsNotNull(whtBishop2.get(), L"Expected a piece at f1");

			Assert::AreEqual(sBishop, whtBishop1.get()->GetSymbol(), L"Expected a bishop at c1");
			Assert::AreEqual(sBishop, whtBishop2.get()->GetSymbol(), L"Expected a bishop at f1");

			//Black Bishops
			auto blkBishop1 = board.GetSquare(Chess::Position::FromAlgebraic("c8")).piece;
			auto blkBishop2 = board.GetSquare(Chess::Position::FromAlgebraic("f8")).piece;

			Assert::IsNotNull(blkBishop1.get(), L"Expected a piece at c8");
			Assert::IsNotNull(blkBishop2.get(), L"Expected a piece at f8");

			Assert::AreEqual(sBishop, blkBishop1.get()->GetSymbol(), L"Expected a bishop at c8");
			Assert::AreEqual(sBishop, blkBishop2.get()->GetSymbol(), L"Expected a bishop at f8");

			//-----------------Checking for pawns-----------------
			std::string positions[8] = { "a", "b", "c", "d", "e", "f", "g", "h"};

			
			for (int player = 0; player < 2; player++)
			{
				for (int pos = 0; pos < 8; pos++)
				{
					//White Pawns
					if (player == 0)
					{
						std::string whitePos = positions[pos] + "2";
						auto pawn = board.GetSquare(Chess::Position::FromAlgebraic(whitePos)).piece;

						Assert::IsNotNull(pawn.get(), L"Missing a white pawn");
						Assert::AreEqual(sPawn, pawn.get()->GetSymbol(), L"Missing a white pawn");
					}
					//Black Pawns
					else
					{
						std::string blackPos = positions[pos] + "7";
						auto pawn = board.GetSquare(Chess::Position::FromAlgebraic(blackPos)).piece;

						Assert::IsNotNull(pawn.get(), L"Missing a black pawn");
						Assert::AreEqual(sPawn, pawn.get()->GetSymbol(), L"Missing a black pawn");
					}
				}
			}
		}


	};
}
