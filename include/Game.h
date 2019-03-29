/* - Como usar esse arquivo:
 *
 * Onde quiser adicionar, por exemplo, SDL_image e SDL_mixer em um arquivo, faça o seguinte e
 * ele incluirá elas automaticamente e de forma multiplataforma (se usar o makefile tbm fornecido).
 */
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"

/************************************************
*					Game.h						*
*************************************************/
class Game {
public:
	~Game();

	void Run();

	SDL_Renderer *GetRenderer();

	State& GetState();

	static Game&GetInstance();

private:

	State* state;

	static Game*instance;

	SDL_Window* window;

	SDL_Renderer* renderer;

	Game( string title, int width,	int height);

};

