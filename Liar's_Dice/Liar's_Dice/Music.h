#pragma once
#include <vector>

using std::vector;
using std::string;

class Music
{
private:
	vector<string> music;

	void setMusic();

public:
	Music();
	~Music();

	void playMusic();
};