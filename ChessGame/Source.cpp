#include <iostream>
#include <sstream>
#include "../ChessProgram/include/Board/Board.hpp"
#include "Colorful_IO.hpp"

#include <Windows.h>

#include "../ChessProgram/include/Players/HumanPlayer.hpp"
using namespace Chess;

int main()
{
	SetConsoleOutputCP(CP_UTF8); //So that we can display the utf codes

	Chess::Board b;

	b.Print();

	//HumanPlayer playerTest(Pieces::Color::WHITE);

	//playerTest.GetMove(Engine::ChessEngine::Get().GetBoard());

	return 0;
}