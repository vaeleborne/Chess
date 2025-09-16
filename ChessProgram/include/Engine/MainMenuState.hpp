#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP
/**
 * @file    MainMenuState.hpp
 * @author  Dylan Morgan
 * @brief   Defines the concrete gamestate for the main menu
 * @date    2025-09-10
 * @version 1.0
 * @copyright MIT License
 */

#include "ChessEngine.hpp"
namespace Chess::Engine
{
	class MainMenuState : public IGameState
	{
	public:
		void Update() override;
	};
}

#endif
