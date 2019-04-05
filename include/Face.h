#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>
#include <string>
#include "Component.h"
#include "GameObject.h"
#include "Sound.h"
#include <memory>
#include <vector>

/************************************************
*					Face.h						*
**************************************************/

using namespace std;

class Face : public Component {

public:

	Face(GameObject& associated);

	void Damage(int damage);

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

private:

	int hitpoints;

};

