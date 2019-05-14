#include "Game.h"
#include "State.h"
#include <iostream>
#include <string>

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"

//Pro meu pc:---------

#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

//--------------------

using namespace std;
using std::cerr;

Game* Game::instance = nullptr;

Game& Game::GetInstance() {

	if (instance != nullptr) {
		return *instance;
	}
	else {
		instance = new Game("Pedro Negrao 170153789", 1024, 600);
		return *instance;
	}

}

Game::Game(string title, int width, int height) {

	if (instance != nullptr) {
		cerr << "\n\n ERRO: o jogo tentou ser instanciado mas a instancia do jogo ja está rodando \n\n";
		exit(1);
	}

	instance = this;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
		cerr << "SDL_Init retornou erro: " << SDL_GetError();
		exit(1);
	}

	if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)) {
		cerr << "\n\n SDL_IMAGE não pode ser inicializado \n\n";
		exit(1);
	}

	if (!Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3)) {
		cerr << "\n\n SDL_MIXER não pode ser inicializado \n\n";
		//exit(1); O monitor mandou comentar 
	}

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
		cerr << "\n\n Mix_OpenAudio retornou erro \n\n";
		exit(1);
	}

	if (Mix_AllocateChannels(32) != 32) {
		cerr << "\n\n não foi possível alocar os 32 canais de audio \n\n";
		exit(1);
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (!window) {
		cerr << "\n\n A janela nao pode ser criada \n\n";
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		cerr << "\n\n Renderer nao pode ser criado \n\n";
		exit(1);
	}

	state = new State();

}

Game::~Game() {

	delete state;
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

State& Game::GetState() {
	return *state;
}

void Game::Run() {

	state->Start();

	while (!state->QuitRequested()) {
		CalculateDeltaTime();
		frameStart = SDL_GetTicks();
		InputManager::GetInstance().Update();
		//cout << "DT: " << dt << endl;
		state->Update(dt);
		state->Render();

		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}

	Resources::ClearImages();
	Resources::ClearMusics();
	Resources::ClearSounds();

}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

void Game::CalculateDeltaTime() {
	dt = (SDL_GetTicks() / 1000.0) - (frameStart / 1000.0);
}

float Game::GetDeltaTime() {
	return dt;
}
