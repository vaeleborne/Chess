#ifndef NEW_GAME_STATE_HPP
#define NEW_GAME_STATE_HPP
/**
 * @file    NewGameState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for starting a new game
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class NewGameState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif
