#include "Timer.h"

Timer::Timer() : time(0) {
}

void Timer::Restart() {
	time = 0;
}

void Timer::Update(float dt) {
	time += dt;
}

float Timer::Get() {
	return time;
}