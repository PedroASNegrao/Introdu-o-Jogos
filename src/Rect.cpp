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
	Vec2 v = this->GetCenter();
	return v.Dist(r.GetCenter());
}

Vec2 Rect::GetCenter() {
	return Vec2((this->w / 2) + this->x, (this->h / 2) + this->y);
}