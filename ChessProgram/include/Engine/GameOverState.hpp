#ifndef GAME_OVER_STATE_HPP
#define GAME_OVER_STATE_HPP
/**
 * @file    GameOverState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for game over
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class GameOverState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif