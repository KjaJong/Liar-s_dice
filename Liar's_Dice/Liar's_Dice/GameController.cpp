#include "GameController.h"
#include "Player.h"
#include "LogicHandler.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;

LogicHandler LH;

int previousPlayer;
vector<int> curBid;
vector<int> newBid;

GameController::GameController(vector<Player> list)
{
	players = list;
	LH = LogicHandler();
}

GameController::~GameController()
{

}

void GameController::pickFirstPlayer()
{
	//pick random player
	int pick = rand() % players.size() + 1;
	curPlayer = pick - 1;
	
	std::cout << "Player " << players[curPlayer].getName() << " has to begin the game." << std::endl;
	curBid = setBet();
}

void GameController::pickFirstPlayer(int player)
{
	if (player >= players.size()) { curPlayer = 0; }
	else { curPlayer = player; }

	checkPlayers();
	rollDice();

	std::cout << "Player " << players[curPlayer].getName() << " has to begin the game." << std::endl;
	curBid = setBet();
}

void GameController::pickNextPlayer()
{
	int amount = players.size();

	if (amount == (curPlayer + 1))
	{
		previousPlayer = curPlayer;
		curPlayer = 0;
	}
	else
	{
		previousPlayer = curPlayer;
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
	players.shrink_to_fit();

	if (players.size() == 1)
	{
		std::cout << "Player " << players[0].getName() << " has won the game." << std::endl;
		system("pause");
		exit(0);
	}
	else if(players.size() <= 0)
	{
		std::cout << "There are no winners, only losers." << std::endl;
		system("pause");
		exit(0);
	}
}

void GameController::deletePlayer(int index)
{
	std::cout << "Player " << players[index].getName() <<  " is out of dice." << std::endl;
	players.erase(players.begin() + index);
}

void GameController::turn()
{
	int choice;

	std::cout << "Choose an action:" << std::endl;
	std::cout << "*Press 1 to raise current bid" << std::endl;
	std::cout << "*Press 2 to call spot on" << std::endl;
	std::cout << "*Press 3 to call bluff" << std::endl;

	std::cin >> choice;

	switch (choice)
	{
		case 1:
			raise();
			break;
		case 2:
			spotOn();
			break;
		case 3:
			callBluff();
			break;
	}
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

void GameController::raise()
{
	bool check;

	newBid = setBet();
	check = LH.raise(&curBid, &newBid);

	if (check)
	{
		//set new current bid
		std::cout << "New bid accepted." << std::endl;
		curBid = newBid;
	}
	else
	{
		//let the user bid again if last bid is incorrect
		std::cout << "Make sure your new bid is higher than the last bid" << std::endl;
		turn();
	}
}

//Method called when callBluff is selected. This removes a dice from either the previous player(true) or the current player(false).
void GameController::callBluff()
{
	vector<int> playerDice = players[previousPlayer].getDice();

	if(LH.callBluff(&playerDice, &curBid))
	{
		players[previousPlayer].reduceDice();
		pickFirstPlayer(previousPlayer);
	}
	else
	{
		players[curPlayer].reduceDice();
		pickFirstPlayer(curPlayer);
	}
}

//Method called when callBluff is selected. This removes a dice from either the whole table(true) or the current player(false).
void GameController::spotOn()
{
	vector<int> playerDice = players[previousPlayer].getDice();

	if(LH.spotOn(&playerDice, &curBid))
	{
		for (int i = 0; i < players.size(); i++) { if (i != curPlayer) players[i].reduceDice(); }
		pickFirstPlayer(curPlayer + 1);
	}
	else
	{
		players[curPlayer].reduceDice();
		pickFirstPlayer(curPlayer);
	}
}


vector<int> GameController::setBet()
{
	//set bet
	string bet;
	
	std::cout << "Please place your bet." << std::endl;
	std::cin >> bet;

	//convert input to a vector of ints
	vector<int> numbers;
	std::istringstream split(bet);
	string number;
	while (getline(split, number, ','))
	{
		int value = std::atoi(number.c_str());
		numbers.push_back(value);
	}

	return numbers;
}