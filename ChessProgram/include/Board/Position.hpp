#ifndef POSITION_HPP
#define POSITION_HPP
/**
 * @file    Position.hpp
 * @author  Dylan Morgan
 * @brief   Defines the struct representing a position on the board!
 * @date    2025-03-22
 * @version 1.0
 * @copyright MIT License

 *
 * This class is part of the ChessEngine and implements the Position struct.
 */
#include <string>

namespace Chess {
	struct Position
	{
		// 0 = 'a'. 7 = 'h'
		unsigned int file; 

		// 0 = '1', 7 = '8'
		unsigned int rank; 

		//CONSTRUCTORS
		Position(unsigned int file_, unsigned int rank_) : file(file_), rank(rank_){}
		Position(const Position& other) : file(other.file), rank(other.rank) {}

		//FUNCTIONS

		/// <summary>
		/// Checks that the position is valid
		/// </summary>
		/// <returns>
		/// True if valid(as long as you are loading from algebraic it will be as that will throw errors if not)
		/// </returns>
		bool IsValid() const
		{
			return file >= 0 && file < 8 && rank >= 0 && rank < 8;
		}

		/// <summary>
		/// Equality overload
		/// </summary>
		/// <param name="other">Other Position</param>
		/// <returns>True if the other rank and file is the same as this ones</returns>
		bool operator==(const Position& other) const
		{
			return file == other.file && rank == other.rank;
		}

		/// <summary>
		/// Converts the position to an algebraic string ie e4
		/// </summary>
		/// <returns>
		/// A string representing the position in algebraic notation
		/// </returns>
		std::string ToAlgebraic() const
		{
			return std::string(1, 'a' + file) + std::string(1, rank + 1);
		}

		/// <summary>
		/// Static function to get a Position given a string in algebraic notation
		/// </summary>
		/// <param name="pos">
		/// The string representing a position
		/// </param>
		/// <returns>
		/// A Position object
		/// </returns>
		static Position FromAlgebraic(const std::string& pos)
		{
			//TODO HANDLE CASE FOR CASTLING
			if (pos.size() < 2)
				throw std::exception("Algebraic string must be at least 2 characters!");


			if (!ValidFile(pos[0]) || !ValidRank(pos[1]))
				throw std::exception("Algebraic string is not a valid representation of a file and rank!");


			return Position(pos[0] - 'a', pos[1] - '1');
		}

	private:
		//Helpers for valid rank and files

		/// <summary>
		/// Checks if a character is a valid rank representation
		/// </summary>
		/// <param name="rank_">
		/// Char representing the rank
		/// </param>
		/// <returns>
		/// True if the char is a valid rank, false otherwise
		/// </returns>
		static bool ValidRank(char rank_)
		{
			return rank_ >= '1' && rank_ <= '8';
		}

		/// <summary>
		/// Call after validating, converts to an unsigned int
		/// </summary>
		/// <param name="rank_">The rank</param>
		/// <returns>
		/// The uint equivalent of a given rank
		/// </returns>
		static unsigned int RankFromChar(char rank_)
		{
			return rank_ - '1';
		}

		/// <summary>
		/// Checks if a character is a valid file representation
		/// </summary>
		/// <param name="file_">
		/// Char representing the file
		/// </param>
		/// <returns>
		/// True if the char is a valid file, false otherwise
		/// </returns>
		static bool ValidFile(char file_)
		{
			return file_ >= 'a' && file_ <= 'h';
		}

		/// <summary>
		/// Call after validating, converts to an unsigned int
		/// </summary>
		/// <param name="file_">The File</param>
		/// <returns>
		/// The uint equivalent of a given file
		/// </returns>
		static unsigned int FileFromChar(char file_)
		{
			return file_ - 'a';
		}
	};
}

#endif