#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP
#include "Player.hpp"
/**
 * @file    HumanPlayer.hpp
 * @author  Dylan Morgan
 * @brief   Defines an implementation of our Player base class to represent a human player!
 * @date    2025-03-28
 * @version 1.0
 * @copyright MIT License
 */

namespace Chess
{
	class HumanPlayer : public Player
	{
	public:
		HumanPlayer(Pieces::Color color, std::string name) : Player(color, name) {}
		~HumanPlayer() {}

		/// <summary>
		/// Prompt user for a move in algebraic format
		/// </summary>
		Move GetMove(const Board& board) override;
	};
}
#endif