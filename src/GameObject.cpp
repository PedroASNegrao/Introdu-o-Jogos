#include "GameObject.h"
#include "Component.h"
#include <typeinfo>


GameObject::GameObject() {
	isDead = false;
	started = false;
	angleDeg = 0;
	box = Rect(0, 0, 0, 0);
}

void GameObject::Update(float dt) {

	for (int i = 0; i < (int)components.size(); ++i) {
		(*components[i]).Update(dt);
	}
}

void GameObject::Render() {

	for (int i = 0; i < (int)components.size(); ++i) {
		(*components[i]).Render();
	}

}

bool GameObject::IsDead() {

	return isDead;

}

void GameObject::RequestDelete() {

	isDead = true;

}

void GameObject::AddComponent(Component *cpt) {

	components.emplace_back(cpt);
	if (started) {
		cpt->Start();
	}

}

void GameObject::RemoveComponent(Component* cpt) {

	int i;
	i = 0;

	shared_ptr<Component>& cpt2 = *(new shared_ptr<Component>(cpt));

	if (!components.empty()) {
		while (i < (int)components.size()) {
			if (components[i] == cpt2) {

				cout << "\nRemovendo objeto\n";

				components.erase(components.begin() + i);

				break;
			}
			i++;
		}
	}

}

Component* GameObject::GetComponent(string type) {
	
	for (auto it = this->components.begin(); it != this->components.end(); it++) {
		if ((*it)->Is(type)) {
			return (*it).get();
		};
	}
	
	return nullptr;  // caso o componente  não exista

}

void GameObject::Start() {
	for (int i = 0; i < (int)components.size(); ++i) {
		(*components[i]).Start();
	}
	started = true;
}

void GameObject::NotifyCollision(GameObject &other) {
	if (!components.empty()) {

		for (int i = 0; i < (int)components.size(); ++i) {
			components[i]->NotifyCollision(other);
		}
	}
}

void GameObject::SetCenter(bool CenterX, bool CenterY) {
    if(CenterX){
        box.x -= box.w/2;
    }

    if(CenterY){
        box.y -= box.h/2;
    }
}

GameObject::~GameObject() {

	int i;
	i = components.size() - 1;

	while (i >= 0) {

		components.erase(components.begin() + i);
		cout << "apagado\n";
		i--;

	}

	this->components.clear();

}