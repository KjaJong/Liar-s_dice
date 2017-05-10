#pragma once
#include <string>

class Player
{
public:
	Player(std::string name);
	~Player();
	void rollDice(int);
	vector<int> getDice();
	void decrementDice();

};

