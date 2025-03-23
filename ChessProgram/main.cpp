#include <iostream>
#include "Board.hpp"
#include <sstream>
#include "Colorful_IO.hpp"
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(CP_UTF8); // Optional if chcp 65001 is already used

	Chess::Board b;

	b.Print();
	return 0;
}