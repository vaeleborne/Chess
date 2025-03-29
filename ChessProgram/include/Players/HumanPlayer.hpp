#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP
#include "Player.hpp"

namespace Chess
{
	class HumanPlayer : public Player
	{
	public:
		HumanPlayer(Pieces::Color color) : Player(color) {}
		~HumanPlayer() {}

		Move GetMove(const Board& board) override;
	};
}
#endif