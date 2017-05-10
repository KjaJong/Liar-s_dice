#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

void rollDice(int);

std::vector<int> diceCup;
std::vector<int> getDice();

Player::Player()
{
}


Player::~Player()
{
}

void rollDice(int amountOfDice)
{
	std::vector<int> cup = {};

	for (int counter = 0; counter < amountOfDice - 1; counter++)
	{
		srand(time(NULL));
		for (int i = 0; i <6; i++)
		{
			std::cout << rand() % 6 + 1 << std::endl;
			cup.push_back(rand() % 6 + 1);
		}
	}
	diceCup = cup;
}

std::vector<int> getDice() {
	return diceCup;
}
