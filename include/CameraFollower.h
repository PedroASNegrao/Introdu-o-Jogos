#pragma once
#include "Component.h"

class CameraFollower : public Component {
public:
	CameraFollower(GameObject& go);

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;
};

