#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include "GameObject.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class TileSet {

public:
	
	TileSet(int tileWidth, int tileHeight, string file);

	~TileSet();

	void RenderTile(unsigned index, float x, float y);

	int GetTileWidth();

	int GetTileHeight();

private:

	Sprite tileSet;

	int rows;

	int columns;

	int tileWidth;

	int tileHeight;

}; 
