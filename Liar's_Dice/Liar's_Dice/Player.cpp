#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

std::vector<int> rollDice(int);

Player::Player()
{
}


Player::~Player()
{
}

std::vector<int> rollDice(int amountOfDice)
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
	return cup;
}