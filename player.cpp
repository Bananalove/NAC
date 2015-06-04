#include "board.h"

void Human::move(Board& board )
{
	// sign == "x" lub "o"
	int move_nr;
	std::cout << "Kolej gracza " << sign << "\n";
	std::cin >> move_nr;

	while (move_nr <1 || move_nr > board.size*board.size)
	{
		std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
		std::cin >> move_nr;
	}
	while (board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] == signs::cross || board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] == signs::nought) // jesli wolne pole
	{
		std::cout << "Blad, podane pole jest juz zapelnione, podaj pole jeszcze raz.\n";
		std::cin >> move_nr;
		while (move_nr <1 || move_nr > board.size*board.size)
		{
			std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
			std::cin >> move_nr;
		}
	}
	board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] = sign;

}
void Computer::move(Board& board)
{
	// sign == "x" lub "o"
	int move_nr;
	std::cout << "Kolej gracza " << sign << "\n";
	std::cin >> move_nr;

	while (move_nr <1 || move_nr > board.size*board.size)
	{
		std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
		std::cin >> move_nr;
	}
	while (board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] == signs::cross || board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] == signs::nought) // jesli wolne pole
	{
		std::cout << "Blad, podane pole jest juz zapelnione, podaj pole jeszcze raz.\n";
		std::cin >> move_nr;
		while (move_nr <1 || move_nr > board.size*board.size)
		{
			std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
			std::cin >> move_nr;
		}
	}
	board.board[(move_nr - 1) / board.size][(move_nr - 1) % board.size] = sign;

}

