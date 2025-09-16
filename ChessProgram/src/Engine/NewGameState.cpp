#include "../../include/Engine/NewGameState.hpp"
#include "../../include/Engine/ExitState.hpp"
#include "../../include/Engine/PlayerOneState.hpp"
#include "../../include/Players/HumanPlayer.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"

namespace Chess::Engine
{
	void NewGameState::Update()
	{
		//Ensure Game Board Is Fresh
		ChessEngine::Get().Reset();

		//TODO: If player types exit at any input point, transition to exit state

		std::string player_input;

		//Loop for game type
		bool valid_input = true;
		int input = 0;
		do
		{
			ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
			std::cout << std::endl;

			ColorfulIO::Write(std::cout, "1) Single Player Game\n2) Two Player Game\n9) Exit\n", true, true, Colors::PROMPT_COLOR);
			ColorfulIO::Write(std::cout, "Enter Choice: ", false, true, Colors::PROMPT_COLOR);

			input = ColorfulIO::GetKey();

			if (input != '1' && input != '2' && input != '9')
				valid_input = false;
			else
				valid_input = true;
		} while (!valid_input);

		//Check For Exit First
		if (input == '9')
		{
			ChessEngine::Get().SetState(std::make_unique<ExitState>());
			return;
		}

		//Get Player(s) name(s)
		std::string player_one_name;
		std::string player_two_name;
		ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
		std::cout << std::endl;
		if (input == '1')
		{
			ColorfulIO::Write(std::cout, "Enter Your Name: ", false, true, Colors::PROMPT_COLOR);
			player_one_name = ColorfulIO::GetTrimmedLineFromUser(std::cin);
			player_two_name = "Bot";
		}
		else if (input == '2')
		{
			ColorfulIO::Write(std::cout, "Enter Name For Player One: ", false, true, Colors::PROMPT_COLOR);
			player_one_name = ColorfulIO::GetTrimmedLineFromUser(std::cin);

			ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
			std::cout << std::endl;
			ColorfulIO::Write(std::cout, "Enter Name For Player Two: ", false, true, Colors::PROMPT_COLOR);
			player_two_name = ColorfulIO::GetTrimmedLineFromUser(std::cin);
		}

		//Add players to the engine and set White to be current player
		ChessEngine::Get().CreatePlayerWhite(std::make_unique<HumanPlayer>(Pieces::Color::WHITE, player_one_name));
		ChessEngine::Get().CreatePlayerBlack(std::make_unique<HumanPlayer>(Pieces::Color::BLACK, player_two_name));
		ChessEngine::Get().SetCurrentPlayer(Pieces::Color::WHITE);

		//Transition to Player 1's Turn State
		ChessEngine::Get().SetState(std::make_unique<PlayerOneState>());
	}
}