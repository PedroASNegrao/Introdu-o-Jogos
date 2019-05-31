#include "Collider.h"

// Adicione o trecho abaixo no come�o do seu Collider.cpp,
// logo ap�s os seus includes e antes de qualquer fun��o.

#ifdef DEBUG
#include "Camera.h"
#include "Game.h"

#include <SDL2/SDL.h>
#endif // DEBUG





// Copie o conte�do dessa fun��o para dentro da sua e adapte o nome das fun��es para as suas.
// Fun��es usadas:
// Rect::GetCenter()				- Retorna um Vec2 no centro do Rect
// Vec2::operator-( const Vec2& )	- Subtrai dois Vec2
// Vec2::Rotate( float rad )		- Rotaciona um Vec2 pelo �ngulo em radianos passado
void Collider::Render() {
#ifdef DEBUG
	Vec2 center(box.GetCenter());
	SDL_Point points[5];

	Vec2 point = (Vec2(box.x, box.y) - center).Rotate(associated.angleDeg / (180 / PI))
		+ center - Camera::pos;
	points[0] = { (int)point.x, (int)point.y };
	points[4] = { (int)point.x, (int)point.y };

	point = (Vec2(box.x + box.w, box.y) - center).Rotate(associated.angleDeg / (180 / PI))
		+ center - Camera::pos;
	points[1] = { (int)point.x, (int)point.y };

	point = (Vec2(box.x + box.w, box.y + box.h) - center).Rotate(associated.angleDeg / (180 / PI))
		+ center - Camera::pos;
	points[2] = { (int)point.x, (int)point.y };

	point = (Vec2(box.x, box.y + box.h) - center).Rotate(associated.angleDeg / (180 / PI))
		+ center - Camera::pos;
	points[3] = { (int)point.x, (int)point.y };

	SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLines(Game::GetInstance().GetRenderer(), points, 5);
#endif // DEBUG
}

Collider::Collider(GameObject &associated, Vec2 scale, Vec2 offset) : Component(associated), scale(scale), offset(offset) {

}

void Collider::Update(float dt) {
	float width = associated.box.w*scale.x, height = associated.box.h*scale.y;
	Vec2 objectCenter = associated.box.GetCenter();

	box.w = width;
	box.h = height;
	box.x = (objectCenter.x - width / 2) + offset.x*(float)sin(associated.angleDeg*PI / 180);
	box.y = (objectCenter.y - height / 2) + offset.y*(float)cos(associated.angleDeg*PI / 180);;

}

bool Collider::Is(string type) {
	return type == "Collider";
}

void Collider::SetScale(Vec2 scale) {
	this->scale = scale;
}

void Collider::SetOffset(Vec2 offset) {
	this->offset = offset;
}