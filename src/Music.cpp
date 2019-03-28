#include "Sprite.h"
#include "Music.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
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
		cerr << "THE MUSIC COULD NOT BE LOADED CORRECTLY";
	}
}

bool Music::IsOpen() {

	return music != nullptr;
	//Checa se music é nula.
}

Music::~Music() {

	if (music) {
		Mix_FreeMusic(music);
	}
	

}



