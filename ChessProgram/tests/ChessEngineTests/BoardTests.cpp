/**
 * @file        BoardTests.cpp
 * @author      Dylan Morgan
 * @brief       Unit tests for the Board class in the Chess Engine.
 *
 *              This file contains tests for board initialization,
 *              piece access and movement, board state tracking (castling and en passant),
 *              and interactions with squares and pieces.
 *
 * @date        2025-03-30
 * @version     1.0
 * @copyright   MIT License
 *
 * @details     Uses Google Test (gtest) to verify correct behavior.
 *              These tests ensure correctness of core board logic
 *              before implementing turn-based gameplay.
 */

#include "pch.h"
#include "../../include/Board/Board.hpp"

using namespace Chess;

/*************************************************************************
*						INITIALIZATION TESTS
***********************************************************************/

TEST(BoardInitialization, InitializesWithNoFatalFailure) {
	EXPECT_NO_FATAL_FAILURE({
		Board board;
		});
}

TEST(BoardInitialization, InitializesWithCorrectNumberOfPieces) {
	Board board;
	int rankOffset = 6;
	for (int rank = 0; rank < 2; rank++)
	{
		for (int file = 0; file < 8; file++)
		{
			EXPECT_TRUE(board.GetPieceAt(Position(file, rank)) != nullptr);
			EXPECT_TRUE(board.GetPieceAt(Position(file, rank + rankOffset)) != nullptr);
		}
	}
}