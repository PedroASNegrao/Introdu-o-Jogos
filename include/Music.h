#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include <string>
#include "SDL_Mixer.h"


/************************************************
*					Music.h						*
**************************************************/

using namespace std;

class Music {
public:

	Music();

	~Music();

	Music(string file);

	void Play(int times = -1);

	void Stop(int msToStop = 1500);

	void Open(string file);

	bool IsOpen();

private:

	Mix_Music* music;

};
