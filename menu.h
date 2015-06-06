#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <memory>
#include "board.h"

int how_difficult()
{
	std::cout << "Podaj stopien trudnosci : \"latwy\", \"sredni\", \"trudny\", \"niepokonany\" \n";
	std::string diff;
	std::cin >> diff;
	while (diff != "latwy" && diff != "sredni" && diff != "trudny" && diff != "niepokonany")
	{
		std::cout << "Podaj stopien trudnosci : \"latwy\", \"sredni\", \"trudny\", \"niepokonany\" \n";
		std::cin >> diff;
	}
	int diff_int = 0;
	if (diff == "latwy")
	{
		diff_int = difficult::easy;
	}
	if (diff == "sredni")
	{
		diff_int = difficult::medium;
	}
	if (diff == "trudny")
	{
		diff_int = difficult::hard;
	}
	if (diff == "niepokonany")
	{
		diff_int = difficult::uwinnable;
	}
	return diff_int;
}


void menu()
{
	std::cout << "Podaj rozmiar planszy ( w zalozeniu mniejszy od 20).\n";
	int size;
	std::cin >> size;
	while (size > 20 || size < 0)
	{
		std::cout << "Podaj rozmiar planszy ( w zalozeniu mniejszy od 20).\n";
		std::cin >> size;
	}
	std::cout << "Pierwszy gacz ( \"x\" ) to czlowiek czy komputer? Wpisz h (human) lub c (computer)\n";
	std::string player;
	std::cin >> player;
	while (player != "h" && player != "c")
	{
		std::cout << "Wybrano bledny znak, wpisz h (human) lub c (computer)\n";
		std::cin >> player;
	}
	std::shared_ptr<Player> ptr1 = nullptr;
	if (player == "h" )
	{
		ptr1.reset(new Human(signs::cross));
	}
	if ( player == "c")
	{
		ptr1.reset(new Computer(signs::cross));
	}
	std::cout << "Drugi gracz ( \"o\" ) gacz to czlowiek czy komputer? Wpisz h (human) lub c (computer)\n";
	std::cin >> player;
	while (player != "h" && player != "c")
	{
		std::cout << "Wybrano bledny znak, wpisz h (human) lub c (computer)\n";
		std::cin >> player;
	}
	std::shared_ptr<Player> ptr2 = nullptr;
	if (player == "h")
	{
		ptr2.reset(new Human(signs::nought));
	}
	if (player == "c")
	{
		ptr2.reset(new Computer(signs::nought));
	}
	Board board(size, ptr1, ptr2, how_difficult());

	board.game();
	

}


#endif