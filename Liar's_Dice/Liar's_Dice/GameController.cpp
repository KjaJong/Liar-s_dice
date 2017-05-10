#include "GameController.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> curBid;
vector<Player> players;
Player curPlayer("");
Player prePlayer("");

GameController::GameController(vector<Player> list)
{
	players = list;
	pickPlayer();
}

GameController::~GameController()
{

}

void GameController::pickPlayer()
{
	int temp = rand() % 10;
	cout << temp << endl;

	/*
	curPlayer = players[(rand() % players.size())];

	cout << "The first player will be" << endl;
	curPlayer.printName();*/
}

void pickOrder()
{

}

void checkPlayers()
{

}

void deletePlayer()
{

}