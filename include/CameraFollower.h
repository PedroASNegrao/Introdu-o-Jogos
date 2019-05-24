#pragma once
#include "Component.h"

class CameraFollower : public Component {
public:
	CameraFollower(GameObject& go, bool adjCenter = false);

	void Update(float dt) override;

	void Render() override;

	bool Is(string type) override;

private:
	bool adjustCenter;

	void AdjustCenter();
};

