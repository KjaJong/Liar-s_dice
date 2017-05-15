#pragma once
#include "Player.h"
#include "LogicHandler.h"
#include <vector>

using std::vector;
using std::string;

class GameController
{
private:
	LogicHandler LH;
	int curPlayer;
	vector<int> curBid;
	vector<Player> players;
	
public:
	GameController(vector<Player> players);
	~GameController();

	void pickFirstPlayer();
	void pickNextPlayer();
	void turn();
	void rollDice();
	void checkPlayers();
	void deletePlayer(int);
};

