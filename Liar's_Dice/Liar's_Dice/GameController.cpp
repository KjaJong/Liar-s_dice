#include "GameController.h"
#include "Player.h"
#include "LogicHandler.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;

GameController::GameController(vector<Player> list)
{
	players = list;
}

GameController::~GameController()
{

}

void GameController::pickFirstPlayer()
{
	//pick random player
	int pick = rand() % players.size() + 1;
	curPlayer = pick - 1;
	
	//set bet
	string bet;
	std::cout << "Player " << players[curPlayer].getName() << " has to begin the game." << std::endl;
	std::cout << "Please place your bet. Seperate your numbers with a comma (1,2,3,4): ";
	std::cin >> bet;

	//convert input to a vector of strings
	vector<string> numbers;
	std::istringstream split(bet);
	string number;
	while (getline(split, number, ','))
	{
		numbers.push_back(number);
	}
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

	std::cout << "It's " << players[curPlayer].getName() << "'s turn." << std::endl;
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
	std::cout << "Player " << players[index].getName() <<  " is out of dice." << std::endl;
	players.erase(players.begin() + index);
}

void GameController::turn()
{
	
}

void GameController::rollDice()
{
	for (int i = 0; i < players.size(); i++)
	{
		int dice = players[i].getAmountOfDice();
		players[i].rollDice(dice);

		std::cout << players[i].getName() << " threw: ";

		vector<int> thrownDice = players[i].getDice();
		for (int j = 0; j < thrownDice.size(); j++)
		{
			std::cout << thrownDice[j] << " ";
		}

		std::cout << std::endl;
	}
}