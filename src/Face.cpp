#include "Face.h"
#include <iostream>
#include <string>

using namespace std;


Face::Face(GameObject &associated) : Component(associated), hitpoints(30) {

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

void Face::Update(float dt) {



}

/*
void Face::Damage(int damage) {

	hitpoints -= damage;

	cout << "Vida: " << hitpoints << endl;

	if (hitpoints <= 0) {

		this->c = (Sound*)associated.GetComponent("Sound");

		if (c != nullptr) {
			c->Play();
			Update(1);
		}

		MakeBoom();
		associated.RemoveComponent(associated.GetComponent("Sprite"));
	}

}

bool Face::MakeBoom() {

	if (hitpoints <= 0) {
			return true;
	}
	else {
		return false;
	}

}

void Face::Update(float dt) {


		if (MakeBoom()) {
			if (c && !c->PlayKabum()){
				associated.RequestDelete();
			}
		}
		

}
*/


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


