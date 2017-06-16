#pragma once
#include <vector>

using std::vector;
using std::string;

class SFX
{
private:
	vector<string> win;
	vector<string> lose;
	vector<string> gameOver;
	vector<string> turn;

	void setWin();
	void setLose();
	void setGameOver();
	void setTurn();
	void playSound(string sound);

public:
	SFX();
	~SFX();

	void playWin();
	void playLose();
	void playGameOver();
	void playTurn();
};