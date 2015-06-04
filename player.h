#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>


namespace results
{
	const int winner = 1;
	const int loser = -1;
	const int draw = 0;
	const int not_end = -100;
}

class Board;
class Player{
	
protected:
	std::string sign;
public:
	Player(std::string signn) :sign(signn) {}
	std::string show_sing() const
	{
		return sign;
	}
	virtual void move(Board& board) = 0;
	
};

class Human : public Player{
public:
	Human(std::string signn) : Player(signn)
	{ }
	
	void move(Board& board);
};

class Computer : public Player{
public:
	Computer(std::string signn) : Player(signn)
	{ }
	int minimax(std::string player, int poziom, Board& board);

	void move(Board& board)
	{
		minimax(sign, 0, board);
	}


	int score(Board& board);
	
	
};







#endif