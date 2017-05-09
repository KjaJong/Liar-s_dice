#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

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

//takes one dice from player
void Player::reduce()
{
	if (dice > 0)
	{
		dice = dice - 1;
	}
}

int Player::diceAmount()
{
	return dice;
}