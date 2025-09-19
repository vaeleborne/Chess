#include <iostream>
#include <sstream>
#include "../ChessProgram/include/Board/Board.hpp"
#include "Colorful_IO.hpp"

#include <Windows.h>

#include "../ChessProgram/include/Players/HumanPlayer.hpp"
#include "../ChessProgram/include/Engine/ChessEngine.hpp"
using namespace Chess;

int main()
{
	SetConsoleOutputCP(CP_UTF8); //So that we can display the utf codes

	Chess::Engine::ChessEngine::Get().Run();

	return 0;
}