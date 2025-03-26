#ifndef IGAMESTATE_HPP
#define IGAMESTATE_HPP
/**
 * @file    IGameState.hpp
 * @author  Dylan Morgan
 * @brief   Defines a gamestate interface for the chess engine.
 * @date    2025-03-25
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess::Engine
{
	class ChessEngine;

	class IGameState
	{
	public:
		virtual ~IGameState() = default;
		virtual void Update(ChessEngine& engine) = 0;
	};
}

#endif