#pragma once
#include "Player.h"
#include <vector>

using namespace std;

class GameController
{
private:
	int curPlayer;
	vector<int> curBid;
	vector<Player> players;
	
public:
	GameController(vector<Player> players);
	~GameController();

	void pickFirstPlayer();
	void pickNextPlayer();
	void checkPlayers();
	void deletePlayer(int);
};

