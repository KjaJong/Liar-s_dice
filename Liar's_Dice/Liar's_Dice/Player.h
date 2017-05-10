#pragma once
#include <string>

class Player
{
public:
	Player(std::string name);
	~Player();
	int diceAmount();
	void reduce(); 
};

