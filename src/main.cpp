#include "Sprite.h"
#include "Music.h"
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

int main(int argc, char** argv) {
	Game::GetInstance().Run();
	return 0;
}