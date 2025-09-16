#ifndef CHESS_ENGINE_HPP
#define CHESS_ENGINE_HPP
#include "IGameState.hpp"
#include "../Board/Board.hpp"
#include "../Players/Player.hpp"
#include "MainMenuState.hpp"
#include <memory>
/**
 * @file    ChessEngine.hpp
 * @author  Dylan Morgan
 * @brief   Defines the ChessEngine which will be our singleton game controller
 * @date    2025-03-25
 * @version 1.0
 * @copyright MIT License
 */
namespace Chess::Engine
{
	class IGameState;
	class ChessEngine
	{
	private:
		static std::unique_ptr<ChessEngine> _instance;
		ChessEngine();

		std::unique_ptr<Board> _board;
		std::unique_ptr<IGameState> _gameState;
		std::unique_ptr<Player> _playerWhite;
		std::unique_ptr<Player> _playerBlack;

		//TODO: Add list of player white captured pieces
		//TODO: Add list of player black captured pieces

		Player* _currentPlayer;					//Raw pointer used to track whose turn it is

		bool running = true;

	public:
		static ChessEngine& Get();
		void SetState(std::unique_ptr<IGameState> newState);
		void Run();
		void Reset();

		void CreatePlayerWhite(std::unique_ptr<Player> player);
		void CreatePlayerBlack(std::unique_ptr<Player> player);
		void SetCurrentPlayer(Pieces::Color color);

		void ProcessMove(const Move& move);

		//TODO: Move to CPP
	    Player& GetCurrentPlayer() {
			if (!_currentPlayer)
				throw "No current player!";
			return *_currentPlayer; }

		Board& GetBoard();

		void Stop();

		//TODO: May want a different function rather than print
		void Print();
	};
}

#endif 