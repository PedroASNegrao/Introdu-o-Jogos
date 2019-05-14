#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Bullet.h"
#include "Sprite.h"
//#include "Game.h"
#include <cmath>

#define PI 3.14159265
#define BULLET_SPEED 250
#define BULLET_MAX_DAMAGE 20
#define BULLET_MAX_DISTANCE 1000

using namespace std;

class Minion : public Component {
public:
	Minion(GameObject& associated, weak_ptr<GameObject> alCenter, float arcOffsetDeg = 0);

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

	void Shoot(Vec2 target);

private:
	GameObject& alienCenter;

	float arc;

};
