#include <iostream>
#include <SDL.h>
#include "Controls.hpp"
#include "CellMap.hpp"
#include <ctime>

void event_handler(SDL_Event event, SDL_Surface *screen, CellMap &cell_map, Controls &controls, bool *quit)
{
	if (event.type == SDL_QUIT)
		*quit = true;
	else if (event.key.keysym.scancode == SDL_SCANCODE_R){
		SDL_FillRect(screen, NULL, OFF_COLOR);
		cell_map.reset();
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_K && event.type == SDL_KEYUP)
		controls.move_low_down();
	else if (event.key.keysym.scancode == SDL_SCANCODE_L && event.type == SDL_KEYUP)
		controls.move_low_up();
	else if (event.key.keysym.scancode == SDL_SCANCODE_O && event.type == SDL_KEYUP)
		controls.move_high_down();
	else if (event.key.keysym.scancode == SDL_SCANCODE_P && event.type == SDL_KEYUP)
		controls.move_high_up();
	else if (event.key.keysym.scancode == SDL_SCANCODE_1 && event.type == SDL_KEYUP)
		controls.set_born(1);
	else if (event.key.keysym.scancode == SDL_SCANCODE_2 && event.type == SDL_KEYUP)
		controls.set_born(2);
	else if (event.key.keysym.scancode == SDL_SCANCODE_3 && event.type == SDL_KEYUP)
		controls.set_born(3);
	else if (event.key.keysym.scancode == SDL_SCANCODE_4 && event.type == SDL_KEYUP)
		controls.set_born(4);
	else if (event.key.keysym.scancode == SDL_SCANCODE_5 && event.type == SDL_KEYUP)
		controls.set_born(5);
	else if (event.key.keysym.scancode == SDL_SCANCODE_6 && event.type == SDL_KEYUP)
		controls.set_born(6);
	else if (event.key.keysym.scancode == SDL_SCANCODE_7 && event.type == SDL_KEYUP)
		controls.set_born(7);
	else if (event.key.keysym.scancode == SDL_SCANCODE_8 && event.type == SDL_KEYUP)
		controls.set_born(8);
}

int main()
{
	SDL_Window *window = nullptr;
	SDL_Surface *screen = nullptr;

	//init sdl FIX UP
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
	
	srand(time(0));

	Controls controls;
	CellMap cell_map;

	controls.display();
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
			event_handler(event, screen, cell_map, controls, &quit);
		cell_map.evolve(screen, controls);
		SDL_UpdateWindowSurface(window);
		SDL_Delay(10);
		
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
