#include "Rect.h"

Rect::Rect() : x(0), y(0), w(0), h(0) {

}

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {

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

