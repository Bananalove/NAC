#include "board.h"

Board::Board(int sizee, Player* player11, Player* player22) : size(sizee), player1(player11), player2(player22)
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
/*
Board::Board(const Board& board2)
{
	//player1(player11), player2(player22)
		


	board = new std::string*[size];
	for (int i = 0; i < size; ++i)
	{
		board[i] = new std::string[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			board[i][j] = board2.board[i][j];
		}
	}
}


Board& Board::operator= (const Board& board2)
{
	if (board != nullptr)
	{
		for (int i = 0; i < size; ++i)
		{
			delete[] board[i];
		}
		delete[] board;
	}
	board = new std::string*[size];
	for (int i = 0; i < size; ++i)
	{
		board[i] = new std::string[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			board[i][j] = board2.board[i][j];
		}
	}
	return *this;
}*/

void Board::print() const
{
	//system("cls");
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::fixed;
		for (int j = 0; j < size; ++j)
		{
			std::cout << std::setw(3) << board[i][j];
		}
		std::cout << "\n";

	}
}

void Board::game()
{
	for (int i = 0; i < size*size; ++i)
	{
		if (i % 2 == 0)
		{
			print();
			player1->move(*this);
			if (result(i))
			{
				return;
			}
		}
		else
		{
			print();
			player2->move(*this);
			if (result(i))
			{
				return;
			}
		}
	}
}

bool Board::winner(std::string sign) const
{
	// wiersze
	bool win_1 = true;
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
	for (int i = 0, j = size - 1; i < size && j >= 0; ++i, --j)
	{
		if (board[i][i] != sign)
		{
			win_3 = false;
		}
		std::cout << "i: " << i << " j " << j << '\n';
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


std::string Board::check()
{

		
		bool win_1 = true; // wiersze
		bool win_2 = true; // kolumny
		bool win_3 = true; // przek¹tna prawa
		bool win_4 = true; // przek¹tna lewa
		bool win_5 = true; // czy wszystkie pola zape³nione

		for (int i = 0; i < size; ++i)
		{
			win_1 = true; // wiersz
			win_2 = true; // kolumny
			for (int j = 1; j < size; ++j)
			{
				if (board[i][j] != signs::cross || board[i][j] != signs::nought)
				{
					win_5 = false;
				}
				if (board[i][j] != board[i][j - 1])
				{
					win_1 = false;
				}
				if (board[j][i] != board[j - 1][i])
				{
					win_2 = false;
				}

			}

			if (win_1)
			{
				return board[i][0];
			}
			if (win_2)
			{
				return board[0][i];
			}
		}

		for (int i = 1, j = size - 2; i < size && j >0; ++i, --j)
		{
			if (board[i][i] != board[i-1][i-1] )
			{
				win_3 = false;
			}
			if (board[i][j] != board[i-1][j+1])
			{
				win_4 = false;
			}
		}
		if ( win_4)
		{
			return board[0][size-1];
		}
		if (win_3)
		{
			return board[0][0];
		}
		if (win_5)
		{
			return " ";
		}
		// if !win_5
		return "w";
}





bool Board::result(int count) const // moze zamiast voida cos innego?
{
	if (winner(signs::cross))
	{
		print();
		std::cout << "Wygral gracz \"x\"! GRATULACJE! \n";
		return true;
	}
	if (winner(signs::nought))
	{
		print();
		std::cout << "Wygral gracz \"o\"! GRATULACJE! \n";
		return true;
	}
	if (count*count + 1 == size)
	{
		print();
		std::cout << "Remis! \n";
		return true;
	}
	return false;
}
