#include "gol.hpp"

int main()
{
	SDL_Window *window = nullptr;
	SDL_Surface *screen = nullptr;

	//init sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	else
		std::cout << "SDL success!\n";

	window = SDL_CreateWindow("Game Of Life Forms",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_SIZE,
			SCREEN_SIZE,
			SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);

	Controls controls;
	CellMap map;
	map.init_map();
	controls.display();
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		//SDL_Event event; why is here in examples?
		while (SDL_PollEvent(&event))
			event_handler(event, &map, &controls, &quit);

		map.evolve(screen, &controls);
		SDL_UpdateWindowSurface(window);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
