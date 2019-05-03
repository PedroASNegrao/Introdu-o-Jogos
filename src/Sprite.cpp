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



Sprite::Sprite(GameObject &associated) : Component(associated), texture(nullptr), width(0), height(0) {

}

Sprite::Sprite(GameObject &associated, string file) : Component(associated), texture(nullptr), width(0), height(0) {
	Sprite(this->associated);
	Open(file);
}

Sprite::~Sprite() {

}

int Sprite::GetHeight() {
	return height;
}

int Sprite::GetWidth() {
	return width;
}

void Sprite::Render() {
	Render(associated.box.x, associated.box.y);
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
	
	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

	if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect) != 0) {
		cerr << "SDL_RenderCopy retornou erro " << SDL_GetError();
		exit(1);
	}
	
}

bool Sprite::IsOpen() {
	if (texture) {
		return true;
	}
	else {
		return false;
	}

}

void Sprite::Update(float dt) {

}

bool Sprite::Is(string type) {
	return (type == "Sprite");
}

