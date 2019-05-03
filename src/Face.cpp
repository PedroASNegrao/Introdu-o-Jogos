#include "Face.h"
#include <iostream>
#include <string>

using namespace std;


Face::Face(GameObject &associated) : Component(associated), hitpoints(30) {

}

void Face::Update(float dt) {

	InputManager IM = InputManager::GetInstance();
	/*
	if (Camera::movment) {
		this->associated.box.x += Camera::speed.x;
		this->associated.box.y += Camera::speed.y;
	}
	*/

	if (IM.MousePress(LEFT_MOUSE_BUTTON)) {
		if (associated.box.Contains({ (float)IM.GetMouseX() /* + Camera::pos.x*/, (float)IM.GetMouseY() /*+ Camera::pos.y*/ }))
			Damage(std::rand() % 10 + 10);
	}

}

void Face::Damage(int damage) {

	hitpoints -= damage;

	cout << "Vida: " << hitpoints << endl;

	if (hitpoints <= 0) {

		Sound* c = (Sound*)associated.GetComponent("Sound");

		if (c != nullptr) {
			c->Play();
		}

		
		associated.RemoveComponent(associated.GetComponent("Sprite"));
		associated.RequestDelete();
	}

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


