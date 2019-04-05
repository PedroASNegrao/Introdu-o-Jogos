#include "Face.h"
#include <iostream>
#include <string>

using namespace std;


Face::Face(GameObject &associated) : Component(associated), hitpoints(30) {}

void Face::Damage(int damage) {

	hitpoints -= damage;

	//cout << "Vida: " << hitpoints << endl;

	if (hitpoints <= 0) {

		Sound* c = (Sound*)associated.GetComponent("Sound");

		if (c != nullptr) {
			c->Play();
		}

		//associated.RequestDelete();
		associated.RemoveComponent(associated.GetComponent("Sprite"));
	}

}

void Face::Update(float dt) {



}

void Face::Render() {



}

bool Face::Is(string type) {

	if (type == "Face") {
		return true;
	}
	else {
		return false;
	}
}


