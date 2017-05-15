#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using std::vector;
using std::string;

Player::Player(string n)
{
	name = n;
	dice = 5;
}

Player::~Player()
{

}

int Player::getAmountOfDice()
{
	return dice;
}

void Player::rollDice(int amountOfDice)
{
	vector<int> cup = {};

	for (int counter = 0; counter < amountOfDice - 1; counter++)
	{
		srand(time(nullptr));
		for (int i = 0; i <6; i++)
		{
			std::cout << rand() % 6 + 1 << std::endl;
			cup.push_back(rand() % 6 + 1);
		}
	}
	diceCup = cup;
}

void Player::reduceDice() {
	dice--;
}

vector<int> Player::getDice() {
	return diceCup;
}

string Player::getName()
{
	return name;
}
