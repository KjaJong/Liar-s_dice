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

	void setWin();
	void setLose();
	void setGameOver();
	void playSound(string sound);

public:
	SFX();
	~SFX();

	void playWin();
	void playLose();
	void playGameOver();
};