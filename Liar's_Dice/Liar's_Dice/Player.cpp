#include <string>
#include <iostream>
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

void rollDice(int);
vector<int> diceCup;
vector<int> getDice();

string name;
int dice;

Player::Player(string n)
{
	name = n;
	dice = 5;
}

Player::~Player()
{

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

void decrementDice() {
	dice--;
}