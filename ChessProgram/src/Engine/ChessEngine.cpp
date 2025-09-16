#include "../../include/Engine/ChessEngine.hpp"

namespace Chess::Engine
{
	std::unique_ptr<ChessEngine> ChessEngine::_instance = nullptr;

	ChessEngine::ChessEngine() : _board(std::make_unique<Board>()), _gameState(std::make_unique<MainMenuState>()){}

	ChessEngine& ChessEngine::Get()
	{
		if (!_instance)
		{
			_instance = std::unique_ptr<ChessEngine>(new ChessEngine());
		}

		return *_instance;
	}

	void ChessEngine::SetState(std::unique_ptr<IGameState> newState)
	{
		_gameState = std::move(newState);
	}
	void ChessEngine::Run()
	{
		running = true;

		while (running)
		{
			if (_gameState != nullptr)
			{
				_gameState->Update();
			}
		}
	}
	Board& ChessEngine::GetBoard()
	{
		return *_board;
	}
	void ChessEngine::Stop()
	{
		running = false;
	}
	void ChessEngine::Print()
	{
		//TODO: Implement
		throw "Not implemented";
	}
}