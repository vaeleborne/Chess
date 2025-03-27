#include <iostream>
#include "../include/Board/Board.hpp"
#include <sstream>
#include "Colorful_IO.hpp"
#include "../include/Engine/ChessEngine.hpp"
#include <Windows.h>

using namespace Chess;
int main()
{
	SetConsoleOutputCP(CP_UTF8); //So that we can display the utf codes

	Engine::ChessEngine::Get().GetBoard().Print();
	return 0;
}