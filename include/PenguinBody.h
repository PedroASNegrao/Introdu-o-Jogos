#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include <iostream>

#include "PenguinCannon.h"
#include "InputManager.h"
#include "CameraFollower.h"
#include "Collider.h"
#include "Bullet.h"
#include "Camera.h"
#include "Being.h"

using namespace std;

class PenguinBody : public Component, public Being {
public:
	explicit PenguinBody(GameObject& associated);
	~PenguinBody() final;

	void Start() override;
	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;

	static PenguinBody* player;

	void NotifyCollision(GameObject& other) override;

private:
	weak_ptr<GameObject> pcannon;
	Vec2 speed;
	float linearSpeed;
	float angle;
	int hp;

};
