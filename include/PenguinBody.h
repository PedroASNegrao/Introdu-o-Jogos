#pragma once

#include <Sprite.h>
#include <PenguinCannon.h>
#include <InputManager.h>
#include <Game.h>
#include <CameraFollower.h>
#include <Collider.h>
#include <Bullet.h>
#include <Camera.h>
#include <Sound.h>
#include <Being.h>
#include <Component.h>

#include <iostream>
#include <cmath>



#define PI 3.14159265

using namespace std;

class PenguinBody : public Component, public Being {
public:
	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;
	void Start() override;

	explicit PenguinBody(GameObject& associated);
	~PenguinBody() final;

	static PenguinBody* player;

	void NotifyCollision(GameObject& other) override;

private:
	weak_ptr<GameObject> pcannon;
	Vec2 speed;
	float linearSpeed;
	float angle;
	int hp;

};