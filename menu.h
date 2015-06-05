#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <memory>
#include "player.h"
void menu()
{
	std::cout << "Pierwszy gacz to czlowiek czy komputer? Wpisz h (human) lub c (computer)\n";
	std::string player;
	std::cin >> player;
	while (player != "h" && player != "c")
	{
		std::cout << "Wybrano bledny znak, wpisz h (human) lub c (computer)\n";
		std::cin >> player;
	}
	











}










#endif