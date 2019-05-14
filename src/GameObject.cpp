#include "GameObject.h"
#include "Component.h"
#include <typeinfo>


GameObject::GameObject() {
	isDead = false;
	started = false;
	angleDeg = 0;
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = 0;
	this->box.h = 0;
}

void GameObject::Update(float dt) {

	int i;
	i = 0;

	while (i < (int)components.size()) {

		(*components[i]).Update(dt);
		i++;

	}
}

void GameObject::Render() {

	int i;
	i = 0;

	while (i < (int)components.size()) {

		(*components[i]).Render();
		i++;

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