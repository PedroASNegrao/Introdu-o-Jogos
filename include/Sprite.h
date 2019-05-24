#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include "Vec2.h"
#include "Timer.h"
#include <iostream>
#include <string>

using namespace std;

/************************************************
*					Sprite.h						*
**************************************************/

class Sprite : public Component {
public:

	Sprite(GameObject &associated);
	Sprite(GameObject &associated, string file, int frameCount = 1, float frameTime = 1, float secondsToSelfDestruct = 0);
	~Sprite();

	void Open(string file);
	void SetClip(int x, int y, int w, int h);
	int GetWidth();
	int GetHeight();
	bool IsOpen();


	void Update(float dt) override;
	void Render() override;
	bool Is(string type) override;


	void Render(int x, int y);
	Vec2 GetScale();
	void SetScaleX(float scaleX, float scaleY);

	void SetFrame(int frame);
	void SetFrameCount(int frameCount);
	void SetFrameTime(float frameTime);

private:

	SDL_Texture *texture;
	int width;
	int height;
	SDL_Rect clipRect;

	Vec2 scale;

	int frameCount;
	int currentFrame;
	float timeElapsed;
	float frameTime;

	Timer selfDestructCout;
	float secondsToSelfDestruct;
};
