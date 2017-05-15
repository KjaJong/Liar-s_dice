#pragma once
#include <vector>

using std::vector;
using std::string;

class Player
{
private:
	string name;
	int dice;
	vector<int> diceCup;

public:
	Player(string name);
	~Player();
	void rollDice(int);
	vector<int> getDice();
	int getAmountOfDice();
	void reduceDice();
	string getName();
};

