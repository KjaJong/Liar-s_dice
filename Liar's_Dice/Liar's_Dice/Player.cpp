#include "Player.h"
#include <string>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

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
		srand(time(NULL));
		for (int i = 0; i <6; i++)
		{
			cout << rand() % 6 + 1 << endl;
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
