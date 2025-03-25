#include <iostream>
#include "../include/Board/Board.hpp"
#include <sstream>
#include "Colorful_IO.hpp"
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(CP_UTF8); //So that we can display the utf codes

	Chess::Board b;

	b.Print();
	return 0;
}