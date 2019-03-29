#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>
#include <string>

using namespace std;

/************************************************
*					Sprite.h						*
**************************************************/

class Sprite {
public:

	Sprite();

	Sprite(string file);

	~Sprite();

	void Open(string file);

	void SetClip(int x, int y, int w, int h);

	void Render(int x, int y);

	int GetWidth();

	int GetHeight();

	bool IsOpen();

private:

	SDL_Texture *texture;

	int width;

	int height;

	SDL_Rect clipRect;
};
