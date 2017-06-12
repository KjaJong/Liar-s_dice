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

	vector<int> setBet();
	void raise();
	void callBluff();
	void spotOn();

public:
	GameController(vector<Player> players);
	~GameController();

	void pickFirstPlayer();
	void pickFirstPlayer(int player);
	void pickNextPlayer();
	void turn();
	void rollDice();
	void checkPlayers();
	void deletePlayer(int);
};

