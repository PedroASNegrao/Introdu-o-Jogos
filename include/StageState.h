#pragma once
#define INCLUDE_SDL
#include "SDL_include.h"
#include "GameObject.h"
#include "Sound.h"
#include "State.h"
#include "TileSet.h"
#include "Sprite.h"
#include "Music.h"

#include <cmath>
#include <vector>
#include <memory>
#include <CameraFollower.h>
#include <TileMap.h>
#include <Alien.h>
#include <PenguinBody.h>
#include <GameData.h>

using namespace std;


class StageState : public State {
public:
	StageState();
	~StageState();

	void LoadAssets();
	void Update(float dt);
	void Render();

	void Start();
	void Pause();
	void Resume();
private:

	Music backgroundMusic;
	TileSet* tileSet;

};
