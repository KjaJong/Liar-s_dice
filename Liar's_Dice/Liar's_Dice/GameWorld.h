#pragma once
#include "Player.h"
class GameWorld
{
private:
	struct Camera {
		float posX = 0;
		float posY = 0;
		float rotX = 0;
		float rotY = 0;
	} camera;

public:
	GameWorld();
	~GameWorld();
	void startGlut(int argc, char* argv[]);
	void animateRollDice(Player player);
	void animateSpotOn(bool isSpotOn);
	void animteCallBluff(bool isBluff);
	
};

