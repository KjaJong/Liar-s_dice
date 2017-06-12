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
	vector<string> getWinSFX();
	vector<string> getLoseSFX();
	vector<string> getGOSFX();
	vector<string> getMusic();
	void playWinSFX(vector<string> files);
	void playLoseSFX(vector<string> files);
	void playGOSFX(vector<string> files);
	void playMusic(vector<string> files);

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

