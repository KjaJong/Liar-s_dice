#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "GameController.h"

using namespace std;

vector<Player> initPlayers();
void gameLoop(vector<Player> players);

int main(int argc, char* argv[])
{
	gameLoop(initPlayers());

	system("pause");
	return 0;
}

//initialize players and return a list of players
vector<Player> initPlayers()
{
	vector<Player> players;
	int amount;

	cout << "Enter the amount of players: " << endl;
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter name for player " << i + 1 << " :" << endl;
		string name;
		cin >> name;
		players.push_back(name);
	}

	return players;
}

void gameLoop(vector<Player> players)
{
	GameController CG = GameController(players);

	//Would start the game loop and handle ending the game.
	//In the final product, this would switch the start screen to the game
	//After that, this will do squat untill the game ends (and after that, i don't know).
}