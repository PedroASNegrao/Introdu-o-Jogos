#include <Camera.h>
#include "CameraFollower.h"
#include "Game.h"

bool CameraFollower::Is(string type) {
	return type == "CameraFollower";
}

void CameraFollower::Update(float dt) {
	associated.box.x = Camera::pos.x;
	associated.box.y = Camera::pos.y;

	if (adjustCenter) {
		AdjustCenter();
		associated.SetCenter();
	}
}

void CameraFollower::Render() {

}

CameraFollower::CameraFollower(GameObject &go, bool adjCenter) : Component(go), adjustCenter(adjCenter) {

}

void CameraFollower::AdjustCenter() {
	associated.box.x += STD_WIDTH / 2;
	associated.box.y += STD_HEIGHT / 2;
}