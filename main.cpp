#include <iostream>
#include "board.h"


int main()
{
	Human gracz1("o");
	Human gracz2("x");
	Board board(3, &gracz1, &gracz2);
	board.print();
	board.game();
	std::cout << "Koniec!\n";
	//std::cout << "Jestem tutaj!\n";






}