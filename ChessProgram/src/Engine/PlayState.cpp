#include "../../include/Engine/PlayState.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"

namespace Chess::Engine
{
	void PlayState::Update()
	{
		//TODO: REMOVE and Implement Update
		ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
		std::cout << std::endl;

		ColorfulIO::Write(std::cout, "\nPlay State!...", true, true);

		
		std::system("pause");

		ChessEngine::Get().Stop();

		//Get the current players move
		Move player_move = ChessEngine::Get().GetCurrentPlayer().GetMove(ChessEngine::Get().GetBoard());

		//Call Engine To Process Move
		ChessEngine::Get().ProcessMove(player_move);

		// Swap Player
		ChessEngine::Get().GetCurrentPlayer().GetColor() == Pieces::Color::WHITE ? ChessEngine::Get().SetCurrentPlayer(Pieces::Color::BLACK) : ChessEngine::Get().SetCurrentPlayer(Pieces::Color::WHITE);

	}
}