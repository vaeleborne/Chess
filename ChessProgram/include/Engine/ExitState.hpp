#ifndef EXIT_STATE_HPP
#define EXIT_STATE_HPP
/**
 * @file   ExitState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for exiting the game
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class ExitState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif