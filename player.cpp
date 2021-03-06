#include "board.h"

void Human::move(Board& board)
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


int Computer::minimax(std::string player, int depth, Board& board)
{
	int licznik = 0;
	int wiersz, kolumna;
	std::string last_val;
	// WIN? LOSE?

	

	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			if (board.board[i][j] != "x" && board.board[i][j] != "o")
			{
				last_val = board.board[i][j];
				board.board[i][j] = player;
				wiersz = i; 
				kolumna = j;  
				++licznik;     //  wolne pola

				bool test = (board.check() == player);

				board.board[i][j] = last_val;
				if (test)
				{
					if (!depth)
					{
						board.board[i][j] = player;
					}

					return player == "x" ? -(board.size*board.size + 1) : (board.size*board.size + 1);
				}
			}
		}
	}
//	std::cout << "jestem w minmaxie!\n";

	// DRAW?

	if (licznik == 1)
	{
		if (!depth)
		{
			board.board[wiersz][kolumna] = player;
		}
		return 0;
	}
	int value = 0;
	int max;
	 max = (player == "x" ? 2 * (board.size*board.size + 1) : -2 * (board.size*board.size + 1));

	 if (depth > board.how_dificult)
	{
	// potencjalna ocena
	return max/2 + to_deep(board, player);
	}

	
	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			if (board.board[i][j] != "x" && board.board[i][j] != "o")
			{
				last_val = board.board[i][j];
				board.board[i][j] = player;

				if (player == "x")
				{
					value = minimax("o", depth + 1, board);
				}
				if (player == "o")
				{
					value = minimax("x", depth + 1, board);
				}
				board.board[i][j] = last_val;

				if (((player == "x") && (value < max)) || ((player == "o") && (value > max)))
				{
					max = value;
					wiersz = i;
					kolumna = j;
				}
			}
		}
	}
	if (!depth)
	{
		board.board[wiersz][kolumna] = player;
	}
	return max;
}

int Computer::to_deep(Board& board, std::string player)
{
	int count_w = 0;
	int max_count_w = 0;
	int count_k = 0;
	int max_count_k = 0;
	int count_dr = 0;
	int max_count_dr = 0;
	int count_dl = 0;
	int max_count_dl = 0;

	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			if (board.board[i][j] == player)
			{
				count_w++;
			}
			if (board.board[j][i] == player)
			{
				count_k++;
			}
		}
		if (count_w > max_count_w)
		{
			max_count_w = count_w;
		}
		count_w = 0;
		if (count_k > max_count_k)
		{
			max_count_k = count_k;
		}
		count_k = 0;
	}

	for (int i = 0, j = board.size - 1; i < board.size && j >= 0; ++i, --j)
	{
		if (board.board[i][i] == player)
		{
			++count_dr;
		}
		if (board.board[i][j] == player)
		{
			++count_dl;
		}
	}
	if (count_dl > max_count_dl)
	{
		max_count_dl = count_dl;
	}
	if (count_dr > max_count_dr)
	{
		max_count_dr = count_dr;
	}

	int max = 0;
	if (max < max_count_dl)
	{
		max = max_count_dl;
	}
	if (max < max_count_dr)
	{
		max = max_count_dr;
	}
	if (max < max_count_k)
	{
		max = max_count_k;
	}
	if (max < max_count_w)
	{
		max = max_count_w;
	}
	if (player == "x")
		max = -max;
	return max;


}

