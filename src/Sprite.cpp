#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Resources.h"
#include "Sprite.h"
#include "Game.h"
#include <string>
#include <iostream>

//Pro meu pc:---------	

#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h" 
//-------------------- 

using namespace std;
using std::cerr;

Sprite::Sprite(GameObject &associated, string file, bool center) : Component(associated), texture(nullptr),
width(0), height(0), scale(1, 1), centered(center) {
	Open(file);
}

Sprite::Sprite(GameObject &associated) : Component(associated), texture(nullptr), width(0), height(0), scale(1, 1) {

}

Sprite::~Sprite() {

}

int Sprite::GetHeight() {
	return height * scale.y;
}

int Sprite::GetWidth() {
	return width * scale.x;
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
	//dimensões da imagem
}

void Sprite::Open(string file) {

	texture = Resources::GetImage(file);

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	associated.box.h = height;
	associated.box.w = width;
	
	SetClip(0, 0, width, height);

}


void Sprite::Render(int x, int y) {
	
	SDL_Rect dstrect;
	dstrect.x = (int)(centered ? x - scale.x*width / 2 : x);
	dstrect.y = (int)(centered ? y - scale.y*height / 2 : y);
	dstrect.w = (int)(clipRect.w*scale.x);
	dstrect.h = (int)(clipRect.h*scale.y);

	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, associated.angleDeg,
		nullptr, SDL_FLIP_NONE);
	
}

bool Sprite::IsOpen() {
	if (texture) {
		return true;
	}
	else {
		return false;
	}

}


void Sprite::Render() {
	//Render(associated.box.x, associated.box.y);
	Render(associated.box.x - (int)Camera::pos.x, associated.box.y - (int)Camera::pos.y);
}

void Sprite::Update(float dt) {

}

bool Sprite::Is(string type) {
	return (type == "Sprite");
}

void Sprite::SetScaleX(float scaleX, float scaleY) {
	if (scaleX != 0) {
		scale.x = scaleX;
		associated.box.x = associated.box.x - clipRect.x*scale.x / 2;
	}

	if (scaleY != 0) {
		scale.y = scaleY;
		associated.box.y = associated.box.y - clipRect.y*scale.y / 2;
	}
}

Vec2 Sprite::GetScale() {
	return scale;
}

