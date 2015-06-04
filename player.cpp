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
int Computer::score(Board& board)
{
	std::string resulted = board.check();
	if (resulted == sign) // player won
	{
		return results::winner;
	}
	if (resulted == " ") // draw
	{
		return results::draw;
	}
	if (resulted == "w")
	{
		return results::not_end;
	}
	// opponent won

	return results::loser;
}
/*
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
*/

int Computer::minimax(std::string player, int poziom, Board& board)
{
	int licznik = 0;
	int w, k;
	std::string last_val;
	// sprawdzamy, czy jest wygrana

	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			if (board.board[i][j] != "x" && board.board[i][j] != "o")
			{
				last_val = board.board[i][j];
				board.board[i][j] = player;
				w = i; k = j;  // gdyby by³ remis
				++licznik;     // zliczamy wolne pola

				bool test = (board.check() == player);

				board.board[i][j] = last_val;
				if (test)
				{
					if (!poziom)
					{
						board.board[i][j] = player;
					}
					return player == "x" ? -1 : 1;
				}
			}
		}
	}

	// sprawdzamy, czy jest remis

	if (licznik == 1)
	{
		if (!poziom)
		{
			board.board[w][k] = player;
		}
		return 0;
	}

	// wybieramy najkorzystniejszy ruch dla gracza

	int v;
	int vmax;

	vmax = (player == "x" ? 2 : -2);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.board[i][j] != "x" && board.board[i][j] != "o")
			{
				last_val = board.board[i][j];
				board.board[i][j] = player;
				v = minimax(player == "x" ? "o" : "x", poziom + 1, board);
				board.board[i][j] = last_val;

				if (((player == "x") && (v < vmax)) || ((player == "o") && (v > vmax)))
				{
					vmax = v; w = i; k = j;
				}
			}
		}
	}

	if (!poziom)
	{
		board.board[w][k] = player;
	}
	return vmax;
}

