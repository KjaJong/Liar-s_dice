#pragma once
#include <vector>

using std::vector;
using std::string;

class SFX
{
private:
	void setWin();
	void setLose();
	void setGameOver();

public:
	SFX();
	~SFX();

	void playWin();
	void playLose();
	void playGameOver();
};