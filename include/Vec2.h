#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <cmath>

class Vec2 {

public:
	float x;
	float y;

	Vec2();

	Vec2(float x, float y);

	Vec2 Sum(Vec2 v, bool sum);
	
	Vec2 MultEsc(int esc);
	
	float Mag();
	
	Vec2 Norm();
	
	float Dist(Vec2 v);
	
	float IncX();
	
	float Incl(Vec2 v);
	
	Vec2 GetRotated(float ang);

	Vec2 operator+(const Vec2& v);
};