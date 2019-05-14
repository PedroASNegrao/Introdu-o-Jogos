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
//#include "Game.h"
#include "GameObject.h"
#define ALIEN_SPEED 300                    // em pixels/s
#define ALIEN__ANGULAR_SPEED -20        // em angleDeg
#define ALIEN_MAX_HP 30

using namespace std;

class Alien : public Component {
public:
	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

	void Start() override;

	Alien(GameObject& associated, int nMinions);

	~Alien();

private:
	class Action {
	public:

		enum ActionType {
			MOVE,
			SHOOT
		};

		Action(ActionType type, float x, float y);

		ActionType type;
		Vec2 pos;
	};

	Vec2 speed;
	int hp;

	queue<Action> taskQueue;
	vector<weak_ptr<GameObject>> minionArray;
	int Minions;
};