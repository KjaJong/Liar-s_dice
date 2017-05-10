#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

vector<Player> initPlayers(vector<string> names);
void gameLoop(vector<Player> players);

int main(int argc, char* argv[])
{
	vector<string> playerNames;
	string players;
	cout << "How many will be playing?" << endl;
	getline(cin, players);

	int amount = stoi(players);

	for (int i = 0; i < amount; i++)
	{
		cout << "Please enter a name for player " << i + 1 << " :" << endl;
		string temp;
		getline(cin, temp);
		playerNames.push_back(temp);
	}


	for (int i2 = 0; i2 < playerNames.size(); i2++)
	{
		cout << "Player " << i2 + 1 << " has this name: " << playerNames[i2] << endl;
	}

	gameLoop(initPlayers(playerNames));
	system("pause");
	return 0;
}

//initialize players and return them
vector<Player> initPlayers(vector<string> players)
{
	vector<Player> playerList;

	for (int i = 0; i < players.size(); i ++)
	{
		Player player = Player(players[i]);
		playerList.push_back(player);
	}

	return playerList;
}

void gameLoop(vector<Player> players)
{

	cout << players.size() << " players joined the game." << endl;
	//Would start the game loop and handle ending the game.
	//In the final product, this would switch the start screen to the game
	//After that, this will do squat untill the game ends (and after that, i don't know).
}