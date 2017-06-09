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
	void setWinSFX();
	void setLoseSFX();
	void setGOSFX();
	void setMusic();
	void playWinSFX();
	void playLoseSFX();
	void playGOSFX();
	void playMusic();

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

