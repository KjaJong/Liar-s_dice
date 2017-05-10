#pragma once
#include "Player.h"
#include <vector>

using namespace std;

class GameController
{
public:
	GameController(vector<Player> players);
	~GameController();
};

