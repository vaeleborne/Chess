#include "../../include/Engine/ChessEngine.hpp"

namespace Chess::Engine
{
	std::unique_ptr<ChessEngine> ChessEngine::_instance = nullptr;

	ChessEngine::ChessEngine() : _board(std::make_unique<Board>()), _gameState(std::make_unique<MainMenuState>()),
		_currentPlayer(nullptr), _playerWhite(nullptr), _playerBlack(nullptr) 
	{	
		_movement_commands = std::stack<std::unique_ptr<Commands::IMoveCommand>>();
	}

	void ChessEngine::Reset() {
		_board = std::make_unique<Board>();
		_currentPlayer = nullptr;
		_playerWhite = nullptr;
		_playerBlack = nullptr;
		_movement_commands.empty();
	}

	void ChessEngine::CreatePlayerWhite(std::unique_ptr<Player> player)
	{
		_playerWhite = std::move(player);
	}

	void ChessEngine::CreatePlayerBlack(std::unique_ptr<Player> player)
	{
		_playerBlack = std::move(player);
	}

	void ChessEngine::SetCurrentPlayer(Pieces::Color color)
	{
		if (color == Pieces::Color::WHITE)
			_currentPlayer = _playerWhite.get();
		else if (color == Pieces::Color::BLACK)
			_currentPlayer = _playerBlack.get();
		else
			_currentPlayer = nullptr;
	}

	void ChessEngine::AddMoveCommand(std::unique_ptr<Commands::IMoveCommand> command)
	{
		_movement_commands.push(std::move(command));
	}

	void ChessEngine::UndoLastMoveCommand()
	{
		//TODO: ERROR HANDLING
		_movement_commands.top()->Undo(*_board.get());
		_movement_commands.pop();
	}

	void ChessEngine::ProcessCurrentMove()
	{
		//TODO: ERROR HANDLING
		_movement_commands.top()->Execute(*_board.get());
	}

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