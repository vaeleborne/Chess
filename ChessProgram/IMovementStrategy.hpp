#ifndef MOVEMENT_STRATEGY_HPP
#define MOVEMENT_STRATEGY_HPP
#include "Position.hpp"
#include <vector>

namespace Chess { class Board; }
namespace Chess::Pieces
{
	class Piece;
	enum class Color;
	class IMovementStrategy
	{
	public:
		virtual std::vector<Position> GetLegalMoves(const Chess::Position& position, const Chess::Board& board, const Color& color) const = 0;
		~IMovementStrategy() = default;
	};
}


#endif