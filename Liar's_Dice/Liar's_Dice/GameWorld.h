#pragma once
#include "Player.h"
class GameWorld
{
private:
	

public:
	void animateRollDice(std::vector<int>);
	GameWorld();
	~GameWorld();
	void startGlut(int argc, char* argv[]);
	void animateRaise(vector<int> dice);
	void animateRollDice(Player player);
	void animateSpotOn(bool isSpotOn);
	void animteCallBluff(bool isBluff);
	
};

