#include <Camera.h>
#include "CameraFollower.h"

bool CameraFollower::Is(string type) {
	return type == "CameraFollower";
}

void CameraFollower::Update(float dt) {
	associated.box.x = Camera::pos.x;
	associated.box.y = Camera::pos.y;
}

void CameraFollower::Render() {

}

CameraFollower::CameraFollower(GameObject &go) : Component(go) {

}