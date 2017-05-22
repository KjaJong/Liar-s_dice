#include "Player.h"
#include <vector>
#include <string>
#include <time.h>

using std::vector;
using std::string;

Player::Player(string n)
{
	srand(time(nullptr));
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

	for (int i = 0; i < amountOfDice; i++)
	{
		cup.push_back(rand() % 6 + 1);
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
