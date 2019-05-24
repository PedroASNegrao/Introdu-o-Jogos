#pragma once

#define PI 3.1415926535

#include "Component.h"
#include "Vec2.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Collider.h"
#include <cmath>

class Bullet : public Component {
public:
	bool targetsPlayer;
	Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite, int frameCount, float frameTime, bool targetsPlayer);

	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;
	int GetDamage();

	void NotifyCollision(GameObject& other) override;

private:
	Vec2 speed;
	float distanceLeft;
	int damage;


};

