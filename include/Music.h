#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>
#include <string>

//Pro meu pc:
#include "SDL_mixer.h"
//-----------



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

