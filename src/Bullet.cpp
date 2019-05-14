#include "Bullet.h"

void Bullet::Update(float dt) {

	associated.box.x += speed.x*dt;
	associated.box.y += speed.y*dt;

	distanceLeft -= sqrt((speed.x*dt)*(speed.x*dt) + (speed.y*dt)*(speed.y*dt));

	if (distanceLeft <= 0) {
		speed.x = 0;
		speed.y = 0;
		associated.RequestDelete();
	}

}

bool Bullet::Is(string type) {
	return type == "Bullet";
}


void Bullet::Render() {

}

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance,
	string sprite) : Component(associated), distanceLeft(maxDistance), damage(damage) {

	associated.angleDeg = 90 - angle * 180 / PI;

	//cout << "Angulo : " << associated.angleDeg << endl;

	Sprite* spr = new Sprite(associated, sprite, true);
	associated.AddComponent(spr);
	associated.box.h = spr->GetHeight();
	associated.box.w = spr->GetWidth();

	this->speed.x = speed * sin(angle);
	this->speed.y = speed * cos(angle);


}

int Bullet::GetDamage() {
	return damage;
}