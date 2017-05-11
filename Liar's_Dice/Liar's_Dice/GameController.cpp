#include "GameController.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

Player curPlayer("");

GameController::GameController(vector<Player> list)
{
	players = list;
	pickFirstPlayer();
	deletePlayer(0);
}

GameController::~GameController()
{

}

void GameController::pickFirstPlayer()
{
	int pick = rand() % players.size() + 1;
	curPlayer = players[pick - 1];
	
	cout << "Player " << curPlayer.getName() << " has to begin the game." << endl;
}

void pickNextplayer()
{

}

void GameController::checkPlayers()
{
	for (int i = 0; i < players.size(); i ++)
	{
		if (players[i].getDice() == 0)
		{
			deletePlayer(i);
		}
	}
}

void GameController::deletePlayer(int index)
{
	cout << "Player " << players[index].getName() <<  " is out of dice." << endl;
	players.erase(players.begin() + index);
}