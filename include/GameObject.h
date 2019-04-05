#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include "Rect.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/************************************************
*					GameObject.h						*
**************************************************/

class Component;

class GameObject {
public:

	GameObject();

	~GameObject();

	void Update(float dt);

	void Render();

	bool IsDead();

	void RequestDelete();

	void AddComponent(Component *cpt);

	void RemoveComponent(Component *cpt);

	Component *GetComponent(string type);
	
	Rect box;

private:

	vector<Component*> components;

	bool isDead;

};

