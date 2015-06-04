#include <iostream>
#include "board.h"


int main()
{
	Computer gracz1("o");
	Computer gracz2("x");
	Board board(3, &gracz1, &gracz2);
	board.print();
	board.game();
	std::cout << "Koniec!\n";






}