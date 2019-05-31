#pragma once
#include <State.h>
#include <Music.h>
#include <Sprite.h>
#include <GameData.h>
#include <CameraFollower.h>
#include <Text.h>

using namespace std;

class EndState : public State {
public:
	EndState();
	~EndState();

	void LoadAssets() override;
	void LoadAssets(string path = "");
	void Update(float dt) override;
	void Render() override;
	void Start() override;
	void Pause() override;
	void Resume() override;

private:
	Music backgroundMusic;
};

