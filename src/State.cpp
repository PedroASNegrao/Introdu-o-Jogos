#include "Game.h"
#include "State.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

using namespace std;

State::State() : bg("./assets/img/ocean.jpg"), music("./assets/audio/stageState.ogg") {
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