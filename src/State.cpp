#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include <string>

#define PI 3.1415926535

using namespace std;
using std::cerr;

State::State() : music("./assets/audio/stageState.ogg") {
	auto mapGO = new GameObject();
	mapGO->box.x = 0;
	mapGO->box.y = 0;

	auto bg = new Sprite(*mapGO, "./assets/img/ocean.jpg");

	auto tileSet = new TileSet(64, 64, "./assets/img/tileset.png");

	auto tileMap = new TileMap(*mapGO, "./assets/map/tileMap.txt", tileSet);

	mapGO->AddComponent(bg);
	mapGO->AddComponent(tileMap);

	objectArray.emplace_back(mapGO);

	quitRequested = false;
	music.Play();
}

void State::LoadAssets() {
	music.Open("assets/audio/stageState.ogg");
}

void State::Render() {
	int i;

	for (i = 0; i < (int)objectArray.size(); ++i) {
		objectArray[i]->Render();
	}
}


bool State::QuitRequested() {
	return quitRequested;
}


void State::Update(float dt) {
	InputManager IM = InputManager::GetInstance();

	if (IM.IsKeyDown(ESCAPE_KEY) || IM.QuitRequested()) {
		quitRequested = true;
	}

	Camera::Update(dt);

	if (IM.KeyPress(SDLK_SPACE)) {
		Vec2 objPos = Vec2(200, 0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(IM.GetMouseX(), IM.GetMouseY());
		AddObject(objPos.x + Camera::pos.x, objPos.y + Camera::pos.y);
	}

	for (int i = 0; i < (int)objectArray.size(); ++i) {
		objectArray[i]->Update(dt);
	}

	for (int i = 0; i < (int)objectArray.size(); ++i) {
		if (objectArray[i]->IsDead()) {
			if (!Mix_Playing(10)) {
				objectArray.erase(objectArray.begin() + i);
			}

		}
	}
}



void State::AddObject(float mouseX, float mouseY) {

	shared_ptr<GameObject> go(new GameObject());


	Sprite *spr = new Sprite((*go), "assets/img/penguinface.png"); // adiciona o rosto do pinguin ao teclar

	go->AddComponent(spr);
	go->box.x = mouseX;
	go->box.y = mouseY;
	go->box.h = spr->GetHeight();
	go->box.w = spr->GetWidth();

	go->AddComponent(new Sound((*go), "assets/audio/boom.wav"));
	go->AddComponent(new Face((*go)));

	objectArray.emplace_back(move(go));
}

State::~State() {
	objectArray.clear();
}