#include "../../include/Engine/PlayState.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"
#include "../../include/Commands/PieceMoveCommand.hpp"

namespace Chess::Engine
{
	void PlayState::Update()
	{
		ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
		std::cout << std::endl;

		//Get the current players move
		std::optional<Move> player_move = ChessEngine::Get().GetCurrentPlayer().GetMove(ChessEngine::Get().GetBoard());

		//Add move as a piece command to the engine, then process it

		if (player_move.has_value())
		{
			ChessEngine::Get().AddMoveCommand(std::make_unique<Commands::PieceCommand>(player_move.value()));

			ChessEngine::Get().ProcessCurrentMove(); //Will check for win here too

			//TODO: Add Option To Undo Move(If player wishes, before going to the next turn)

			// Swap Player
			ChessEngine::Get().GetCurrentPlayer().GetColor() == Pieces::Color::WHITE ? ChessEngine::Get().SetCurrentPlayer(Pieces::Color::BLACK) : ChessEngine::Get().SetCurrentPlayer(Pieces::Color::WHITE);
		}
	}
}