#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "TileSet.h"
#include <string>
#include <iostream>

using namespace std;
using std::cerr;

TileSet::TileSet(int tileWidth, int tileHeight, string file) : tileHeight(tileHeight), tileWidth(tileWidth), rows(0), columns(0), tileSet(*new GameObject(), file) {

	tileSet.Open(file);

	if (tileSet.IsOpen() == false) {
		cout << "Erro ao abrir o arquivo: "" << file << "" no TileSet.";
		exit(1);
	}

	columns = tileSet.GetWidth() / tileWidth;
	rows = tileSet.GetHeight() / tileHeight;
	

}

void TileSet::RenderTile(unsigned index, float x, float y) {


	float mIndex = rows * columns;
	float tX, tY;

	//cout << "x: " << x << "\ny: " << x << "\nindex: " << index << endl;
	//cout << "columns: " << columns << "\nrows: " << rows << endl;
	//system("pause");

	if (index >= mIndex) {
		cout << "Invalid index (" << index << "), max index: " << (mIndex - 1);
		exit(1);
	}

	tY = index / columns;
	tX = index % columns;

	tileSet.SetClip(tX*tileWidth, tY*tileHeight, tileWidth, tileHeight);
	tileSet.Render((float)x, (float)y);

}

int TileSet::GetTileWidth() {
	return tileWidth;
}

int TileSet::GetTileHeight() {
	return tileHeight;
}

TileSet::~TileSet() {
}