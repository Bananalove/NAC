#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

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

	void move(Board& board);
};





#endif