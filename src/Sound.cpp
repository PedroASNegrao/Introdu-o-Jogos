#include "Sound.h"
#include <iostream>
#include <string>
#include "Component.h"
#include "GameObject.h"

//Pro meu pc:
#include "SDL_mixer.h"
//-----------

using namespace std;

Sound::Sound(GameObject &associated) : Component(associated), chunk(nullptr) {

}

Sound::Sound(GameObject &associated, string file) : Component(associated), chunk(nullptr) {

	Open(file);

}

void Sound::Stop() {
	if (chunk != nullptr) {
		Mix_HaltChannel(-1); //-1 aloca no canal aberto
	}

}

void Sound::Play(int times) {
	if (chunk != nullptr) {
		Mix_PlayChannel(10, chunk, times - 1);
	}
}


void Sound::Open(string file) {

	chunk = Mix_LoadWAV(file.c_str());

	if (chunk == nullptr) {
		cout << "Error: " << SDL_GetError();
		cout << "\nFalha em abrir o som: '" << file.c_str() << "'.\n";
		exit(1);
	}

}

bool Sound::IsOpen() {

	if (chunk != nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void Sound::Update(float dt) {

}

void Sound::Render() {

}

bool Sound::Is(string type) {
	return (type == "Sound");
}

Sound::~Sound() {
	
	if (chunk != nullptr) {
		Stop();		// chamar o Halt
		Mix_FreeChunk(chunk);
	}

}
