#include "../../include/Engine/PlayerOneState.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"

namespace Chess::Engine
{
	void PlayerOneState::Update()
	{
		//TODO: REMOVE and Implement Update
		ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
		std::cout << std::endl;

		ColorfulIO::Write(std::cout, "\nPlayer One State!...", true, true);

		
		std::system("pause");

		ChessEngine::Get().Stop();

		//TODO: Get Player One Move
		Move player_move = ChessEngine::Get().GetCurrentPlayer().GetMove(ChessEngine::Get().GetBoard());

		//TODO: Call Engine To Process Move
		ChessEngine::Get().ProcessMove(player_move);

		//TODO: Transition State (Not needed? Can Just Use a 'Play' state?

	}
}