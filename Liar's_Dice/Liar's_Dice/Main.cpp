#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <future>
#include "Player.h"
#include "GameController.h"
#include "GameWorld.h"
#include "Music.h"

using std::vector;
using std::string;
using std::thread;
using std::async;
using std::future;

vector<Player> initPlayers();
void gameLoop(vector<Player> players);
void gameWorld(int argc, char* argv[]);
void gameMusic();

extern GameWorld GW;
Music M;

int main(int argc, char* argv[])
{
	//TODO start multithreading

	//Starts the gameworld thread
	future<void> gameWorldThread = async(gameWorld, argc, argv);

	//Starts the game music thread
	future<void> gameMusicThread = async(gameMusic);

	//Starts the game loop thread
	future<void> gameLoopThread = async(gameLoop, initPlayers());

	return 0;
}

//initialize players and return a list of players
vector<Player> initPlayers()
{
	vector<Player> players;
	int amount;

	std::cout << "Enter the amount of players: " << std::endl;
	std::cin >> amount;
	

	for (int i = 0; i < amount; i++)
	{
		std::cout << "Enter name for player " << i + 1 << " :" << std::endl;
		string name;
		std::cin >> name;
		players.push_back(name);
	}

	return players;
}

void gameLoop(vector<Player> players)
{
	GameController CG = GameController(players);

	CG.rollDice();

	CG.pickFirstPlayer();

	while (true)
	{
		CG.pickNextPlayer();
		CG.turn();
	}

	//Would start the game loop and handle ending the game.
	//In the final product, this would switch the start screen to the game
	//After that, this will do squat untill the game ends (and after that, i don't know).
}

void gameWorld(int argc, char* argv[])
{
	GW.startGlut(argc, argv);
}

void gameMusic()
{
	M.playMusic();
}