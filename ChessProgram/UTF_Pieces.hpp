#ifndef UTF_PIECES_HPP
#define UTF_PIECES_HPP
/**
 * @file    UTF_Pieces.hpp
 * @author  Dylan Morgan
 * @brief   Defines some constant strings which represent pieces, note we don't need different colors as our IO library will handle that!
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This file is largely just a helper of variables to be used accross files.
 *
 */
#include <string>

namespace Chess::Pieces
{
	const std::string KING_UTF = "\xE2\x99\x9A";
	const std::string QUEEN_UTF = "\xE2\x99\x9B";

	const std::string ROOK_UTF = "\xE2\x99\x9C";
	const std::string BISHOP_UTF = "\xE2\x99\x9D";
	const std::string KNIGHT_UTF = "\xE2\x99\x9E";
	const std::string PAWN_UTF = "\xE2\x99\x99";
	const std::string SQUARE_UTF = "\xE2\x96\xA0";
}

#endif