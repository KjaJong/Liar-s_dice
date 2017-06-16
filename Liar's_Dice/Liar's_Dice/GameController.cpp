#include "GameController.h"
#include "GameWorld.h"
#include "Player.h"
#include "LogicHandler.h"
#include "ReadDice.h"
#include "SFX.h"
#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;

LogicHandler LH;
ReadDice RD;
SFX sound;
GameWorld GW;

int previousPlayer;
vector<int> curBid;

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
	
	std::cout << "Player " << players[curPlayer].getName() << " has to begin the game." << std::endl;
	raise();
}

void GameController::pickFirstPlayer(int player)
{
	if (player >= players.size()) { curPlayer = 0; }
	else { curPlayer = player; }

	checkPlayers();
	rollDice();

	std::cout << "Player " << players[curPlayer].getName() << " has to begin the game." << std::endl;
	raise();
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

	if(players.size() <= 0)
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
	sound.playGameOver();
}

void GameController::turn()
{
	std::cout << "Place one die and press enter if you are ready." << std::endl;
	std::cout << "Set die value 1 to raise current bid" << std::endl;
	std::cout << "Set die value 2 to call spot on" << std::endl;
	std::cout << "Set die value 3 to call bluff" << std::endl;
	system("pause");

	vector<int> dice = RD.CheckDice(1);

	if (dice.size() == 1)
	{
		switch (dice[0])
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
		default:
			std::cout << "Key not recognized." << std::endl;
			turn();
			break;
		}
	}
	else
	{
		std::cout << "Place place one die." << std::endl;
		turn();
	}
}

void GameController::rollDice()
{
	//set curbid to null
	curBid.clear();

	for (int i = 0; i < players.size(); i++)
	{
		//check amount of dice
		int diceAmount = players[i].getAmountOfDice();
		std::cout << players[i].getName() << " has to throw " << diceAmount << " dice." << std::endl;

		//set new dice vector
		std::cout << "Throw your dice and press enter." << std::endl;
		system("pause");
		vector<int> diceList = RD.CheckDice(diceAmount);

		if (diceList.size() == diceAmount)
		{
			players[i].setDice(diceList);
			GW.animateRollDice(players[i]);			
		}
		else
		{
			std::cout << "Please throw the correct amount of dice." << std::endl;
			i--;
		}
	}
}

void GameController::raise()
{
	vector<int> read = setBet();
	vector<int> newBid;

	//check if the correct amount of dice is thrown
	if (read.size() == 2)
	{
		//TEST
		std::cout << "adding: " << read[0] << " " << read[1] << "'s" << std::endl;
		//END TEST

		for (int i = 0; i < read[0]; i++)
		{
			newBid.push_back(read[1]);
		}

		//check if new bid is possible
		bool check = LH.raise(&curBid, &newBid);

		if (check)
		{
			//set new current bid
			std::cout << "New bid accepted." << std::endl;
			curBid = newBid;
			GW.animateRaise(newBid);
		}
		else
		{
			//let the user bid again if last bid is incorrect
			std::cout << "Make sure your new bid is higher than the last bid." << std::endl;
			raise();
		}
	}
	else
	{
		//let the user bid again if last bid is incorrect
		std::cout << "Make sure you throw the correct amount of dice." << std::endl;
		raise();
	}
	
}

//Method called when callBluff is selected. This removes a dice from either the previous player(true) or the current player(false).
void GameController::callBluff()
{
	vector<int> playerDice = players[previousPlayer].getDice();

	//check if bluff is correct
	if(LH.callBluff(&playerDice, &curBid))
	{
		sound.playWin();
		GW.animteCallBluff(true);
		players[previousPlayer].reduceDice();
		pickFirstPlayer(previousPlayer);
	}
	else
	{
		sound.playLose();
		GW.animteCallBluff(false);
		players[curPlayer].reduceDice();
		pickFirstPlayer(curPlayer);
	}
}

//Method called when callBluff is selected. This removes a dice from either the whole table(true) or the current player(false).
void GameController::spotOn()
{
	vector<int> playerDice = players[previousPlayer].getDice();

	//check if spoton is correct
	if(LH.spotOn(&playerDice, &curBid))
	{
		sound.playWin();
		GW.animateSpotOn(true);
		for (int i = 0; i < players.size(); i++) { if (i != curPlayer) players[i].reduceDice(); }
		pickFirstPlayer(curPlayer + 1);
	}
	else
	{
		GW.animateSpotOn(false);
		sound.playLose();
		players[curPlayer].reduceDice();
		pickFirstPlayer(curPlayer);
	}
}

vector<int> GameController::setBet()
{
	std::cout << "Use your dice to place a bid and press enter if you are ready." << std::endl;
	system("pause");

	return RD.CheckDice(0);
}