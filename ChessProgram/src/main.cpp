#include <iostream>
#include "../include/Board/Board.hpp"
#include <sstream>
#include "Colorful_IO.hpp"
#include "../include/Engine/ChessEngine.hpp"
#include <Windows.h>

#include "../include/Players/HumanPlayer.hpp"

using namespace Chess;
int main()
{
	SetConsoleOutputCP(CP_UTF8); //So that we can display the utf codes

	HumanPlayer playerTest(Pieces::Color::WHITE, "name");

	//playerTest.GetMove(Engine::ChessEngine::Get().GetBoard());

	//Engine::ChessEngine::Get().GetBoard().Print();
	return 0;
}