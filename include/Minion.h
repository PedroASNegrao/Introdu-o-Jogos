#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Bullet.h"
#include "Sprite.h"
#include "Being.h"
#include "Alien.h"
#include "Collider.h"
#include "PenguinBody.h"
#include "PenguinCannon.h"

#include <cmath>


#define BULLET_SPEED 250

using namespace std;

class Minion : public Component {
public:
	Minion(GameObject& associated, weak_ptr<GameObject> alCenter, float arcOffsetDeg = 0);

	void NotifyCollision(GameObject& other) override;

	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;

	void Shoot(Vec2 target);

private:
	GameObject& alienCenter;

	float arc;

};
