#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>
#include <string>

using namespace std;

/************************************************
*					Component.h						*
**************************************************/

class GameObject;

class Component {
public:

	Component(GameObject &associated);

	virtual ~Component();

	virtual void Update(float dt) = 0;

	virtual void Render() = 0;

	virtual bool Is(string type) = 0;

	virtual void Start();

protected:

	GameObject& associated;

}; 
