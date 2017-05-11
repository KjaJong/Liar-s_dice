#pragma once
#include <string>
using namespace std;

class Player
{
private:
	string name;
	int dice;

public:
	Player(std::string name);
	~Player();
	int getDice();
	void reduce(); 
	std::string getName();
};

