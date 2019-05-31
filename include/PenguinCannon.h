#pragma once
#include <Component.h>
#include <GameObject.h>
#include <Timer.h>
#include <CameraFollower.h>
#include <Sprite.h>
#include <PenguinBody.h>
#include <Bullet.h>
#include <InputManager.h>
#include <Camera.h>
#include <Collider.h>


#include <iostream>

#define BULLET_SPEED 200

using namespace std;

class PenguinCannon : public Component {
	public:
		PenguinCannon(GameObject& associated, weak_ptr<GameObject> penguinBody);

		void Update(float dt);
		void Render();
		bool Is(string type);
		void Shoot();

	private:
		weak_ptr<GameObject>pbody;
		float angle = 0;

		Timer timer;
};

