#pragma once
#include <Component.h>
#define STD_WIDTH 1024
#define STD_HEIGHT 600

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

