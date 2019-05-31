#include "Component.h"

Component::Component(GameObject &associated) : associated(associated) {
	
}

Component::~Component() {

}

void Component::Start() {

}

Vec2 Component::GetPosition() {
	return associated.box.GetCenter();
}

void Component::NotifyCollision(GameObject &other) {

}

