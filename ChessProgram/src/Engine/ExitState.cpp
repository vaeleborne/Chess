#include "../../include/Engine/ExitState.hpp"

namespace Chess::Engine
{
	void ExitState::Update()
	{
		ColorfulIO::Write(std::cout, "Exiting...", true, true);

		//TODO: REMOVE
		std::system("pause");

		ChessEngine::Get().Stop();

	}
}