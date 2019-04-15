#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include <string>

#define PI 3.1415926535

using namespace std;
using std::cerr;

State::State() : music("./assets/audio/stageState.ogg") {
	auto mapGO = new GameObject();
	mapGO->box.x = 0;
	mapGO->box.y = 0;

	auto bg = new Sprite(*mapGO, "./assets/img/ocean.jpg");

	auto tileSet = new TileSet(64, 64, "./assets/img/tileset.png");

	auto tileMap = new TileMap(*mapGO, ".assets/map/tileMap.txt", tileSet);

	mapGO->AddComponent(bg);
	mapGO->AddComponent(tileMap);

	objectArray.emplace_back(mapGO);

	quitRequested = false;
	music.Play();
}

void State::LoadAssets() {
	music.Open("assets/audio/stageState.ogg");
}

void State::Render() {
	int i;

	for (i = 0; i < (int)objectArray.size(); ++i) {
		objectArray[i]->Render();
	}
}


bool State::QuitRequested() {
	return quitRequested;
}
void State::Update(float dt) {
	int i;

	Input();

	i = 0;

	for (i = 0; i < (int)objectArray.size(); ++i) {	//++i incrementa antes de ler qa função
		objectArray[i]->Update(dt);
	}
	
	for (i = 0; i < (int)objectArray.size(); ++i) {

		if (objectArray[i]->IsDead()) {

			//if (!Mix_Playing(10)) {

				 objectArray.erase(objectArray.begin() + i);	//apaga o objeto na posição desejada

			//}

		}
	}
}



void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for (int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if (go->box.Contains({ (float)mouseX, (float)mouseY })) {
					Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) {
						// Aplica dano
						cout << "clique\n";
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						//break;
					}
					break;
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2(200.0, 0.0).GetRotated(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				AddObject(objPos.x, objPos.y);
			}
		}
	}
}

State::~State() {
	objectArray.clear();
}



void State::AddObject(float mouseX, float mouseY) {

	shared_ptr<GameObject> go(new GameObject());


	Sprite *spr = new Sprite((*go), "assets/img/penguinface.png"); // adiciona o rosto do pinguin ao teclar

	go->AddComponent(spr);
	go->box.x = mouseX;
	go->box.y = mouseY;
	go->box.h = spr->GetHeight();
	go->box.w = spr->GetWidth();

	go->AddComponent(new Sound((*go), "assets/audio/boom.wav"));
	go->AddComponent(new Face((*go)));

	objectArray.emplace_back(move(go));
}

