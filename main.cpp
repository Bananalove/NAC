#include <iostream>
#include "board.h"
void algor();


int main()
{
	Computer gracz1("o");
	Human gracz2("x");
	Board board(3, &gracz1, &gracz2);
	board.print();
	board.game();
	std::cout << "Koniec!\n";
	//std::cout << "Jestem tutaj!\n";






}