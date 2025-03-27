#include "../../include/Engine/ChessEngine.hpp"

namespace Chess::Engine
{
	std::unique_ptr<ChessEngine> ChessEngine::_instance = nullptr;

	ChessEngine::ChessEngine() : _board(std::make_unique<Board>()){}

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
		//TODO: Implement
		throw "Not implemented";
	}
	Board& ChessEngine::GetBoard()
	{
		return *_board;
	}
	void ChessEngine::Stop()
	{
		//TODO: Implement
		throw "Not implemented";
	}
	void ChessEngine::Print()
	{
		//TODO: Implement
		throw "Not implemented";
	}
}