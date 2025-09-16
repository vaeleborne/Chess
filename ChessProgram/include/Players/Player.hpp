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
#include "../Board/Board.hpp"
#include <string>

namespace Chess
{

	class Player
	{
	protected:
		Pieces::Color _color;
		Move ParseAlgebraicMove(const std::string& input, const Board& board) const;
		bool IsValidAlgebraic(const std::string& input) const;
		std::string _name;

	public:
		Player(Pieces::Color color, std::string name) : _color(color), _name(name){}
		virtual ~Player() = default;

		Pieces::Color GetColor() const { return _color; }

		void SetName(std::string name);

		virtual Move GetMove(const Board& board) = 0; //Pure virtual
	};
}

#endif