#include "Game.h"
#include "State.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

State::State() : bg("./Recursos/img/ocean.jpg"), music("./Recursos/audio/stageState.ogg") {
	quitRequested = false;
	music.Play();
}

void State::LoadAssets() {

}

void State::Update(float dt) {

	if (SDL_QuitRequested() == true) {
		quitRequested = true;
	}

}

bool State::QuitRequested() {
	return quitRequested;
}

void State::Render() {
	bg.Render(0, 0);
}




