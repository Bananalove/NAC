#ifndef BOARD_H
#define BOARD_H
#include <iomanip>
#include <memory>
#include "player.h"
namespace signs 
{
	const std::string nought = "o";
	const std::string cross = "x";
}
namespace difficult
{
	const int easy = 1;
	const int medium = 3;
	const int hard = 4;
	const int uwinnable = 10;
}


class Board
{
	std::shared_ptr<Player>  player1;
	std::shared_ptr<Player>  player2;
	int how_dificult;
	std::string** board;
	int size; 
	public:

	Board() : size(0), board(nullptr), player1(nullptr), player2(nullptr) {}

	Board(int sizee, std::shared_ptr<Player> player11, std::shared_ptr<Player> player22, int difficult);

	
	//Board(const Board& board2);

	//Board& operator= (const Board& board2);


	~Board()
	{
		for (int i = 0; i < size; ++i)
		{
			delete [] board[i];
		}
		delete [] board;
	}

	void print() const;
		
	
	void game();
	
	std::string check();

	bool result(int count) const; 


	bool winner(std::string sign) const;
	friend Player;
	friend Human;
	friend Computer;
};





#endif