#include "../../include/Engine/ExitState.hpp"
#include "../../include/Helpers/ChessColorDefines.hpp"

namespace Chess::Engine
{
	void ExitState::Update()
	{
		ColorfulIO::Write(std::cout, "\nExiting...", true, true);

		//TODO: REMOVE
		std::system("pause");

		ChessEngine::Get().Stop();

	}
}