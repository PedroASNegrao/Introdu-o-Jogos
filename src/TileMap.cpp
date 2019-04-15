#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "TileMap.h"
#include <string>
#include <iostream>
#include <stdio.h>

using std::cerr;
using namespace std;

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated),
tileSet(tileSet), mapDepth(0),
mapHeight(0), mapWidth(0),
tileMatrix(*new vector<int>()) {

	Load(file);
}

TileMap::~TileMap() {
	delete tileSet;
	tileMatrix.clear();
}

void TileMap::Load(string file) {
	ifstream tileMapFile;
	string line;

	tileMapFile.open("./assets/map/tileMap.txt");	//abrir o tilemap

	if (!tileMapFile.is_open()) {
		cerr << "tileMap.txt nso pode ser aberto. \n";
		exit(1);
	}

	tileMapFile >> line;
	sscanf_s(line.c_str(), "%d,%d,%d,", &mapHeight, &mapWidth, &mapDepth);

	if (mapWidth == -1 || mapHeight == -1 || mapDepth == -1) { // if one of these values are STILL -1...
		cerr << "mapHeight, mapWidth OR mapDepth nao puderam ser lidos. \n";
		tileMapFile.close();
		exit(1);
	}

	int tileIndex;
	char comma;

	for (int i = 0; i < mapWidth*mapHeight*mapDepth; i++) {
		tileMapFile >> tileIndex;
		tileMapFile >> comma;
		tileMatrix.push_back(tileIndex - 1);
	}

	tileMapFile.close();
}

void TileMap::SetTileSet(TileSet *tileSet) {
	this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z) {
	int index = (z*mapWidth*mapHeight) + (y*mapWidth) + x;
	return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
	int i, j, index;
	int tWidth = tileSet->GetTileWidth(), tHeight = tileSet->GetTileHeight();


	for (i = 0; i < mapHeight; ++i) {
		for (j = 0; j < mapWidth; ++j) {
			index = At(j, i, layer);
			if (index > -1) {
				tileSet->RenderTile(index, (j*tWidth) - cameraX, (i*tHeight) - cameraY);
			}
		}
	}
}

void TileMap::Render() {

	for (int i = 0; i < mapDepth; ++i) {
		RenderLayer(i);
	}
}

int TileMap::GetWidth() {
	return mapWidth;
}

int TileMap::GetHeight() {
	return mapHeight;
}

int TileMap::GetDepth() {
	return mapDepth;
}

void TileMap::Update(float dt) {

}

bool TileMap::Is(string type) {
	return type == "TileMap";
}