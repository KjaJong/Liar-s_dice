#pragma once
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
	string name;
	int dice;
	vector<int> diceCup;

public:
	Player(std::string name);
	~Player();
	void rollDice(int);
	vector<int> getDice();
	int getAmountOfDice();
	void reduceDice();
	std::string getName();
};

