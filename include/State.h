#pragma once
#include "Music.h"
#include "Sprite.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"


/************************************************
*					State.h						*
**************************************************/
class State {
public:

	State();

	bool QuitRequested();

	void LoadAssets();

	void Update(float dt);

	void Render();

private:
	
	Sprite bg;

	Music music;

	bool quitRequested;

}; 
