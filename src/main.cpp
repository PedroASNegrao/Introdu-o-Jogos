#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"

#include <Sprite.h>
#include <Music.h>
#include <Game.h>
#include <fstream>
#include <StageState.h>
#include <TitleState.h>
#include <time.h>

#include <string>

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Game& g = Game::GetInstance();
	g.Push("TitleState");
	g.Run();
	return 0;
}