#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
class Board
{
	char** board;
	int size; 
	public:
	Board(int sizee) : size(sizee)
	{
		board = new char*[size];
		for (int i = 0; i < size; ++i)
		{
			board[i] = new char[size];
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				board[i][j] = *(std::to_string(size*i + j).c_str());
			}
		}
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				std::cout << board[i][j] << " ";

				std::cout << "\n";
			}
		}
	}





};





#endif