#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include "Music.h"
#include "Sprite.h"
#include "SDL_include.h"
#include "GameObject.h"
#include "Sound.h"
#include "Vec2.h"
#include "Rect.h"
#include "TileSet.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"
#include "Alien.h"

#include <memory>
#include <vector>
#include <cmath>

using namespace std;

/************************************************
*					State.h						*
**************************************************/
class State {
public:

	State();

	~State();

	bool QuitRequested();

	void LoadAssets();

	void Update(float dt);

	void Render();

	void Start();

	weak_ptr<GameObject> AddObject(shared_ptr<GameObject> go);

	weak_ptr<GameObject> GetObjectPtr(GameObject* go);

private:
	
	//Sprite bg;

	Music music;

	bool quitRequested;

	void AddObject(float mouseX, float mouseY);

	vector<shared_ptr<GameObject>> objectArray;

	bool started;

}; 

