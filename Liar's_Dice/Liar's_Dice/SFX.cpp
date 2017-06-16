#include "SFX.h"
#include <irrKlang.h>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using namespace irrklang;

ISoundEngine *SFXEngine;
ISound *soundEffect;

SFX::SFX()
{
	SFXEngine = createIrrKlangDevice();
	setWin();
	setLose();
	setGameOver();
}

SFX::~SFX()
{

}

//correct guess sound effects
void SFX::setWin()
{
	win.push_back("media/sfx/correct/Deez nuts.mp3");
	win.push_back("media/sfx/correct/Gotcha.mp3");
	win.push_back("media/sfx/correct/Right ding.mp3");
	win.push_back("media/sfx/correct/Victory.mp3");
}

//wrong guess sound effects
void SFX::setLose()
{
	lose.push_back("media/sfx/wrong/Losing horn.mp3");
	lose.push_back("media/sfx/wrong/Fart.mp3");
	lose.push_back("media/sfx/wrong/Nope.mp3");
	lose.push_back("media/sfx/wrong/Punch.mp3");
	lose.push_back("media/sfx/wrong/Wilhelm scream.mp3");
}

//game over sound effects
void SFX::setGameOver()
{
	gameOver.push_back("media/sfx/game over/Beep.mp3");
	gameOver.push_back("media/sfx/game over/Mario.mp3");
	gameOver.push_back("media/sfx/game over/PacMan.mp3");
	gameOver.push_back("media/sfx/game over/Shutdown.mp3");
}

void SFX::playWin()
{
	std::cout << win.size() << std::endl;

	int random = rand() % win.size() + 1;
	string sound = win[random - 1];

	playSound(sound);
}

void SFX::playLose()
{
	int random = rand() % lose.size() + 1;
	string sound = lose[random - 1];

	playSound(sound);
}

void SFX::playGameOver()
{
	int random = rand() % gameOver.size() + 1;
	string sound = gameOver[random - 1];

	playSound(sound);
}

void SFX::playSound(string sound)
{
	string effect = sound;

	if (soundEffect == nullptr)
	{
		soundEffect = SFXEngine->play2D(effect.c_str(), false, false, true);
	}
	else if (soundEffect->isFinished())
	{
		soundEffect = SFXEngine->play2D(effect.c_str(), false, false, true);
	}
	else
	{
		while (true)
		{
			_sleep(500);
			
			if (soundEffect->isFinished())
			{
				soundEffect = SFXEngine->play2D(effect.c_str(), false, false, true);
				break;
			}
		}
	}
}