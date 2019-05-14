#pragma once
#include "GameObject.h"
#include "Vec2.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

class Camera {

public:
	static Vec2 pos;
	static Vec2 speed;

	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);

	static bool movment;

private:
	
	static GameObject* focus;
};

