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

	}
}