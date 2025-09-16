#ifndef PLAYER_TWO_STATE_HPP
#define PLAYER_TWO_STATE_HPP
/**
 * @file    PlayerTwoState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for player two's turn
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class PlayerTwoState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif
