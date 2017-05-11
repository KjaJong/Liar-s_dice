#pragma once
#include "Player.h"
#include <vector>

using namespace std;

class GameController
{
private:
	vector<int> curBid;
	vector<Player> players;
	
public:
	GameController(vector<Player> players);
	~GameController();

	void pickFirstPlayer();
	void checkPlayers();
	void deletePlayer(int);
};

