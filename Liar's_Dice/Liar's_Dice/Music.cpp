#include "Music.h"
#include <irrKlang.h>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace irrklang;

vector<string> music;

Music::Music()
{

}

Music::~Music()
{

}

void Music::setMusic()
{
	music.push_back("media/music/Japanese Jazz.mp3");
	music.push_back("media/music/KSP Build 1.mp3");
}

void Music::playMusic()
{
	ISoundEngine *musicEngine = createIrrKlangDevice();
	ISound *song;
	int tracks = music.size();
	int curTrack = 1;

	//set volume
	musicEngine->setSoundVolume(0.5f);

	//play first song
	string track = music[curTrack - 1];
	song = musicEngine->play2D(track.c_str(), false, false, true);

	//loop through other songs
	while (true)
	{
		//check if a song is active
		if (song->isFinished())
		{
			//increment track number
			curTrack++;

			//check if playlist reached its end
			if (curTrack > tracks)
			{
				curTrack = 1;
			}

			//play next song
			track = music[curTrack - 1];
			song = musicEngine->play2D(track.c_str(), false, false, true);
		}
		else
		{
			_sleep(500);
		}
	}
}