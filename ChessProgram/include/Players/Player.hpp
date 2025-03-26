#ifndef PLAYER_HPP
#define PLAYER_HPP
/**
 * @file    Player.hpp
 * @author  Dylan Morgan
 * @brief   Defines a base class for a player object, useful as we will have human and ai players
 * @date    2025-03-25
 * @version 1.0
 * @copyright MIT License
 */
#include "../Movement/Move.hpp"
#include "../Board/Board.hpp"
#include "../Pieces/Piece.hpp"

namespace Chess
{
	class Player
	{
	protected:
		Pieces::Color _color;
	public:
		Player(Pieces::Color color) : _color(color){}
		virtual ~Player() = default;

		Pieces::Color GetColor() const { return _color; }

		virtual Move GetMove(const Board& board) = 0; //Pure virtual
	};
}

#endif