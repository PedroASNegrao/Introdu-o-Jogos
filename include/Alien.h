#pragma once
#include <queue>
#include <vector>
#include "Component.h"
#include "Vec2.h"
#include "InputManager.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Camera.h"
#include "Minion.h"
#include "Rect.h"
#include "GameObject.h"
#include "Being.h"
#include "Timer.h"
#include "PenguinBody.h"

#define COOLDOWN 4
#define ALIEN_SPEED 300                    // em pixels/s
#define ALIEN__ANGULAR_SPEED -20        // em angleDeg
#define ALIEN_MAX_HP 30

using namespace std;

class Alien : public Component, public Being {
public:
	static int alienCount;

	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;
	void Start() override;

	Alien(GameObject& associated, int nMinions, float offset);
	~Alien();

	void NotifyCollision(GameObject& other) override;


private:
	enum AlienState {
		MOVING,
		RESTING
	};

	Vec2 speed;
	int hp;
	vector<weak_ptr<GameObject>> minionArray;

	AlienState state;
	Timer restTimer;
	Vec2 destination;

	float timeOffset = 0;

	void Shoot(Vec2 tg);
};