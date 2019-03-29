#include "Sprite.h"
#include "Music.h"
#include "Game.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

using namespace std;

int main(int argc, char** argv) {
	Game::GetInstance().Run();
	return 0;
}