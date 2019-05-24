#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "TileSet.h"
#include "Component.h"
#include "Camera.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class TileMap : public Component {

public:

	TileMap(GameObject& associated, string file, TileSet* tileSet);

	~TileMap() override;

	void Load(string file);

	void SetTileSet(TileSet* tileSet);

	int& At(int x, int y, int z = 0);

	void Render() override;

	void Update(float dt) override;

	bool Is(string type) override;

	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

	int GetWidth();

	int GetHeight();

	int GetDepth();

private:

	vector<int> tileMatrix;

	TileSet* tileSet;

	int mapWidth = -1;

	int mapHeight = -1;

	int mapDepth = -1;

};

