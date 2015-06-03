#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include <iomanip>

namespace signs 
{
	const std::string nought = "o";
	const std::string cross = "x";
}

class Board
{
	std::string** board;
	int size; 
	public:
	Board(int sizee) : size(sizee)
	{
		board = new std::string*[size];
		for (int i = 0; i < size; ++i)
		{
			board[i] = new std::string[size];
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				board[i][j] = std::to_string(size*i + j + 1);
			}
		}
	}
	~Board()
	{
		for (int i = 0; i < size; ++i)
		{
			delete [] board[i];
		}
		delete [] board;
	}
	void print()
	{
		system("cls");
		for (int i = 0; i < size; ++i)
		{
			std::cout << std::fixed;
			for (int j = 0; j < size; ++j)
			{
				std::cout << std::setw(3) <<  board[i][j] ;
			}
			std::cout << "\n";

		}
	}

	void count()
	{
		int move;
		std::cout << "Kolej gracza \n";
		std::cin >> move;
		std::cout << (move - 1) / size << "   " << (move - 1) % size << "\n";
	}
	void man_move(std::string sign)
	{
		// sign == "x" lub "o"
		print();
		int move;
		std::cout << "Kolej gracza " << sign <<"\n";
		std::cin >> move;
		
		while (move <1 || move > size*size)
		{
			std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
			std::cin >> move;
		}
		while (board[(move - 1) / size][(move - 1) % size] == signs::cross || board[(move - 1) / size][(move - 1) % size] == signs::nought ) // jesli wolne pole
		{
			std::cout << "Blad, podane pole jest juz zapelnione, podaj pole jeszcze raz.\n";
			std::cin >> move;
			while (move <1 || move > size*size)
			{
				std::cout << "Blad, podane pole jest poza plansza, podaj pole jeszcze raz.\n";
				std::cin >> move;
			}
		}
		board[(move - 1) / size][(move - 1) % size] = sign;

	}
	void game()
	{
		for (int i = 0; i < size*size; ++i)
		{
			if (i % 2 == 0)
			{
				man_move(signs::nought);
				if (result(i))
				{
					return;
				}
				

			}
							else 
			{
				man_move(signs::cross);
				if (result(i))
				{
					return;
				}
			}
		}
	}
	 

	bool result(int count) // moze zamiast voida cos innego?
	{
		if (winner(signs::cross)) 
		{
			std::cout << "Wygral gracz \"x\"! GRATULACJE! \n";
			return true;
		}
		if (winner(signs::nought))
		{
			std::cout << "Wygral gracz \"o\"! GRATULACJE! \n";
			return true;
		}
		if (count*count + 1 == size)
		{
			std::cout << "Remis! \n";
			return true;
		}
		return false;
	}


	bool winner(std::string sign)
	{
		// wiersze
		bool win_1= true;
		bool win_2 = true;
		bool win_3 = true;
		bool win_4 = true;

		for (int i = 0; i < size; ++i)
		{
			win_1 = true; // wiersz
			win_2 = true; // kolumny
			for (int j = 0; j < size; ++j)
			{
				if (board[i][j] != sign)
				{
					win_1 = false;
				}
				if (board[j][i] != sign)
				{
					win_2 = false;
				}
			
			}

			if (win_1 || win_2)
			{
				return true;
			}
		}
		for (int i = 0, j = size - 1; i < size && j >0; ++i, --j)
		{
			if (board[j][j] != sign)
			{
				win_3 = false;
			}
			if (board[i][j] != sign)
			{
				win_4 = false;
			}
		}
		if (win_3 || win_4)
		{
			return true;
		}

		return false;
	}

};





#endif