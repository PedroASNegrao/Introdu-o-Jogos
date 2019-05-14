#pragma once

#define PI 3.14159265

#include "Component.h"
#include "Vec2.h"
#include "GameObject.h"
#include "Sprite.h"
#include <cmath>

class Bullet : public Component {
public:
	Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite);

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

	int GetDamage();

private:
	Vec2 speed;

	float distanceLeft;

	int damage;


};

