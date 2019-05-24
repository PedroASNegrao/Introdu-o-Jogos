#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Vec2.h"
#include "Music.h"

#include <string>
#include <unordered_map>

class Rect {

public:

	float x, y, w, h;


	Rect();
	Rect(float x, float y, float w, float h);


	Rect SumVec2(Vec2 v);
	Vec2 GetCenter();
	float DistRecs(Rect r);
	bool Contains(Vec2 v);
	
};
