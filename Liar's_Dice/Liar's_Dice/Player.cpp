#include "Player.h"
#include <string>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>


void rollDice(int);
vector<int> diceCup;
vector<int> getDice();

Player::Player(string n)
{
	name = n;
	dice = 5;
}

Player::~Player()
{

}

int Player::getDice()
{
	return dice;
}

void rollDice(int amountOfDice)
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

vector<int> getDice() {
	return diceCup;
}

string Player::getName()
{
	return name;
}
