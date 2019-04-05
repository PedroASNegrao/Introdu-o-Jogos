#include "GameObject.h"
#include "Component.h"
#include <typeinfo>

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {

	int i;
	i = components.size() - 1;

	while (i >= 0) {

		delete components[i];
		i--;

	}

	components.clear();

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

	this->components.emplace_back(cpt);

}

void GameObject::RemoveComponent(Component* cpt) {

	int i;
	i = 0;

	if (!components.empty()) {
		while (i < (int)components.size()) {
			if (components[i] == cpt) {

				//cout << "Removendo objeto\n";

				components.erase(components.begin() + i);

				break;
			}
			i++;
		}
	}

}

Component* GameObject::GetComponent(string type) {

	int i;
	i = 0;

	if (!components.empty()) {

		while ( i < (int)components.size()) {
			if ((*components[i]).Is(type)) {
				return components[i];
			}
			i++;
		}
	}

	return nullptr;  // caso o componente  não exista

}



