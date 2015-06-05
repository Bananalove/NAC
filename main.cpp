#include <iostream>
#include "board.h"
// pomiar czasu
#include <ctime>
#include <cstdlib>

int main()
{
	system("pause");
	Computer gracz1("x");
	//Computer gracz2("x");
	Human gracz2("o");
	Board board(3, &gracz1, &gracz2, difficult::hard);
	board.print();
	srand(time(NULL));
	auto  end = std::clock(), start = std::clock();
	board.game();
	end = std::clock();
	std::cout << "Czas trwania gry to : " << (((float)(end - start)) / CLOCKS_PER_SEC) * 1000 << " milisekund.\n";
	std::cout << "Koniec!\n";






}