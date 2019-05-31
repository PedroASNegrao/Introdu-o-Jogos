#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Being.h"
#include <cmath>

#define PI 3.14159265
#define BULLET_SPEED 150

using namespace std;

class Minion : public Component, public Being {
public:
	Minion(GameObject& associated, weak_ptr<GameObject> alCenter, float arcOffsetDeg = 0);

	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;

	void Shoot(Vec2 target);

	void NotifyCollision(GameObject& other) override;

private:
	GameObject& alienCenter;
	float arc;

};