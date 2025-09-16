#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP
/**
 * @file    PlayState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for player one's turn
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class PlayState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif
