#include "Camera.h"

#define STD_WIDTH 1024
#define STD_HEIGHT 600

#define SPEED 400

GameObject* Camera::focus = nullptr;
Vec2 Camera::pos = *new Vec2();
Vec2 Camera::speed = *new Vec2();
bool Camera::movment = false;

void Camera::Unfollow() {
	focus = nullptr;
}

void Camera::Follow(GameObject *newFocus) {
	focus = newFocus;
}

void Camera::Update(float dt) {
	//bool pressionado;
	//pressionado = false;

	if (focus != nullptr) {
		Camera::pos.x = focus->box.x + STD_WIDTH / 2;
		Camera::pos.y = focus->box.y + STD_HEIGHT / 2;
	}
	else {
		//pressionado = true;
		Camera::speed.x = SPEED;
		Camera::speed.y = SPEED;

		InputManager IM = InputManager::GetInstance();

		//Move para cima
		if (IM.IsKeyDown(UP_ARROW_KEY)) {
			Camera::pos.y -= Camera::speed.y * dt;
		}
		//Move pra baixo
		else if (IM.IsKeyDown(DOWN_ARROW_KEY)) {
			Camera::pos.y += Camera::speed.y * dt;
		}
		//Move pra direita
		else if (IM.IsKeyDown(RIGHT_ARROW_KEY)) {
			Camera::pos.x += Camera::speed.x * dt;
		}
		//Move pra esquerda
		else if (IM.IsKeyDown(LEFT_ARROW_KEY)) {
			Camera::pos.x -= Camera::speed.x * dt;
		}
	}
/*
	if (pressionado == true) {
		pos = pos + speed;
		movment = true;
	}
	else{
		movment = false;
	}
*/
}