#include "Sprite.h"
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>

using namespace std;
using std::cerr;

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite() {
	if (IsOpen() == false) {
	SDL_DestroyTexture(texture);
	}
}

int Sprite::GetHeight() {
	return height;
}

int Sprite::GetWidth() {
	return width;
}

void Sprite::Open(string file) {

	if (texture) {
		SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	if (!texture) {
		cerr << "IMG_LoadTexture retornou erro: " << SDL_GetError();
		exit(1);
	}

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	SetClip(0, 0, width, height);

}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
	//dimensões da imagem
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

	/*
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect* srcrect;
	SDL_Rect* dstrect;
	*/
}

bool Sprite::IsOpen() {
	if (texture) {
		return true;
	}
	else {
		return false;
	}
	
}
