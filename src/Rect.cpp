#include "Rect.h"

Rect::Rect() {

this->x = 0;
this->y = 0;
this->w = 0;
this->h = 0;

}

Rect::Rect(float x, float y, float w, float h){

this->x = x;
this->y = y;
this->w = w;
this->h = h;

}

Vec2 Rect::CenterRec() {
	return Vec2((this->w / 2) + this->x, (this->h / 2) + this->y);
}

Rect Rect::SumVec2(Vec2 v) {
	return Rect(v.x + this->x, v.y + this->y, this->w, this->h);
}

bool Rect::Contains(Vec2 v) {
	if (v.x < (this->w + this->x) && v.x >= this->x && v.y < (this->h + this->y) && v.y >= this->y) {
		return true;
	}
	else {
		return false;
	}
}

float Rect::DistRecs(Rect r) {
	Vec2 v = this->CenterRec();
	return v.Dist(r.CenterRec());
}

void Rect::Centralize() {
	x = x - (w / 2);
	y = y - (h / 2);
}

Rect Rect::operator+(Vec2 vector) {
	Rect rect;

	rect.x = this->x + vector.x;
	rect.y = this->y + vector.y;
	rect.w = this->w;
	rect.h = this->h;

	return rect;
}

Rect Rect::operator=(Vec2 vec) {
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

Rect Rect::operator+=(Vec2 vec) {
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}
