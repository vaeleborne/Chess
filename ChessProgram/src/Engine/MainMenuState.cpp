
#include "../../include/Engine/MainMenuState.hpp"
#include "../../include/Engine/ExitState.hpp"
#include "../../include/Engine/NewGameState.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"


namespace Chess::Engine
{
	void MainMenuState::Update() 
	{
		bool valid_input = true;
		int input = 0;

		do 
		{
			ColorfulIO::WriteHeading(std::cout, "Chess++", 60, 5, true, true, Colors::HEADING_COLOR);
			std::cout << std::endl;

			ColorfulIO::Write(std::cout, "1) New Game\n9) Exit\n", true, true, Colors::PROMPT_COLOR);
			ColorfulIO::Write(std::cout, "Enter Choice: ", false, true, Colors::PROMPT_COLOR);

			input = ColorfulIO::GetKey();

			if (input != '1' && input != '9')
				valid_input = false;
			else
				valid_input = true;

		} while (!valid_input);

		//Once here we have a valid choice, set the game state accordingly
		input == '1' ? ChessEngine::Get().SetState(std::make_unique<NewGameState>()) : ChessEngine::Get().SetState(std::make_unique<ExitState>());	
	}
}