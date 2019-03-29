#include "Sprite.h"
#include "Music.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

using namespace std;

Music::Music() {
	music = nullptr;
}


Music::Music(string file) {
	music = nullptr;
	Open(file);
}

void Music::Play(int times) {
	if (music) {
		Mix_PlayMusic(music, times);
	}
	else {
		cerr << "musica nao tocou pois nao foi instanciada";
	}
}

void Music::Stop(int msToStop) {

	Mix_FadeOutMusic(msToStop);

}

void Music::Open(string file) {

	music = Mix_LoadMUS(file.c_str());

	if (!music) {
		cerr << "a musica não foi carregada corretamente";
	}
}

bool Music::IsOpen() {
	if (music != nullptr) {
		return true;
	}
	else{
		return false;
	}

	//Checa se music é nula.
}

Music::~Music() {

	if (music) {
		Mix_FreeMusic(music);
	}
	

}



