#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>
#include <string>
#include "Component.h"

//Pro meu pc:
#include "SDL_mixer.h"
//-----------


/************************************************
*					Sound.h						*
**************************************************/

using namespace std;

class Sound : public Component {
public:

	Sound(GameObject& associated);

	Sound(GameObject& associated, string file);

	~Sound();

	void Play(int times = 1);

	void Stop();

	void Open(string file);

	bool IsOpen();

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

private:

	Mix_Chunk* chunk;

	int chanel;

};
