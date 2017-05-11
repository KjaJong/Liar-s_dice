#include "GameController.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

GameController::GameController(vector<Player> list)
{
	players = list;
}

GameController::~GameController()
{

}

void GameController::pickFirstPlayer()
{
	int pick = rand() % players.size() + 1;
	curPlayer = pick - 1;
	
	cout << "Player " << players[curPlayer].getName() << " has to begin the game." << endl;
}

void GameController::pickNextPlayer()
{
	int amount = players.size();

	if (amount == (curPlayer + 1))
	{
		curPlayer = 0;
	}
	else
	{
		curPlayer = curPlayer + 1;
	}

	cout << "It's " << players[curPlayer].getName() << "'s turn." << endl;
}

void GameController::checkPlayers()
{
	for (int i = 0; i < players.size(); i ++)
	{
		if (players[i].getAmountOfDice() == 0)
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