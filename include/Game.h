#pragma once
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include <State.h>


#include <string>
#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

class Game {

	int frameStart;
	float dt;

	static Game *instance;

	State* storedState;
	SDL_Window* window;
	SDL_Renderer* renderer;

	stack<unique_ptr<State>> stateStack;

	void CalculateDeltaTime();

public:
	Game(string title, int width, int height);
	~Game();

	static Game& GetInstance();
	SDL_Renderer* GetRenderer();
	State& GetCurrentState();

	void Push(string type);

	void Run();

	float GetDeltaTime();
};