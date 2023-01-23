#include <iostream>
#include <SDL.h>
#include "Controls.hpp"
#include "CellMap.hpp"

static inline void event_handler(SDL_Event event, CellMap &map, Controls &controls, bool *quit)
{
	if (event.type == SDL_QUIT)
		*quit = true;
	if (event.key.keysym.scancode == SDL_SCANCODE_R){
		//SDL_UpdateWindowSurface(window);
		map.init_map();
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_K && event.type == SDL_KEYUP)
		controls.move_low_down();
	if (event.key.keysym.scancode == SDL_SCANCODE_L && event.type == SDL_KEYUP)
		controls.move_low_up();
	if (event.key.keysym.scancode == SDL_SCANCODE_O && event.type == SDL_KEYUP)
		controls.move_high_down();
	if (event.key.keysym.scancode == SDL_SCANCODE_P && event.type == SDL_KEYUP)
		controls.move_high_up();
	if (event.key.keysym.scancode == SDL_SCANCODE_1 && event.type == SDL_KEYUP)
		controls.set_born(1);
	if (event.key.keysym.scancode == SDL_SCANCODE_2 && event.type == SDL_KEYUP)
		controls.set_born(2);
	if (event.key.keysym.scancode == SDL_SCANCODE_3 && event.type == SDL_KEYUP)
		controls.set_born(3);
	if (event.key.keysym.scancode == SDL_SCANCODE_4 && event.type == SDL_KEYUP)
		controls.set_born(4);
	if (event.key.keysym.scancode == SDL_SCANCODE_5 && event.type == SDL_KEYUP)
		controls.set_born(5);
	if (event.key.keysym.scancode == SDL_SCANCODE_6 && event.type == SDL_KEYUP)
		controls.set_born(6);
	if (event.key.keysym.scancode == SDL_SCANCODE_7 && event.type == SDL_KEYUP)
		controls.set_born(7);
	if (event.key.keysym.scancode == SDL_SCANCODE_8 && event.type == SDL_KEYUP)
		controls.set_born(8);
}

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
	controls.display();
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		//SDL_Event event; why is here in examples?
		while (SDL_PollEvent(&event))
			event_handler(event, map, controls, &quit);

		map.evolve(screen, controls);
		SDL_UpdateWindowSurface(window);
		SDL_Delay(10);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
