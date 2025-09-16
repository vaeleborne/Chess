#ifndef PLAYER_ONE_STATE_HPP
#define PLAYER_ONE_STATE_HPP
/**
 * @file    PlayerOneState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for player one's turn
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class PlayerOneState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif
