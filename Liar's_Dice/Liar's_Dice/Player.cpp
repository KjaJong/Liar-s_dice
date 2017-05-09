#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

string name;
int dice;
bool playing;

Player::Player(string n)
{
	name = n;
	dice = 5;
	playing = true;
}

Player::~Player()
{

}

//takes one dice from player
void reduce()
{
	if (dice > 0)
	{
		dice = dice - 1;
	}


	if (dice == 0)
	{
		playing = false;
	}
}

string toString()
{
	return name + " has dice";
}