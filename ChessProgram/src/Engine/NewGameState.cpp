#include "../../include/Engine/NewGameState.hpp"

namespace Chess::Engine
{
	void NewGameState::Update()
	{
		ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, ColorfulIO::Colors::Foreground::YELLOW);
		ColorfulIO::Write(std::cout, "New Game!", true, true);

		//TODO: REMOVE and implement proper new game
		std::system("pause");

		ChessEngine::Get().Stop();

	}
}