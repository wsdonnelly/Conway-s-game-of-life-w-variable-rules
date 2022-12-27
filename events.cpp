#include "gol.hpp"

void event_handler(SDL_Event event, CellMap *map, Controls *controls, bool *quit)
{
	if (event.type == SDL_QUIT)
		*quit = true;
	if (event.key.keysym.scancode == SDL_SCANCODE_R){
		//SDL_UpdateWindowSurface(window);
		map->init_map();
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_K && event.type == SDL_KEYUP)
		controls->move_low_down();
	if (event.key.keysym.scancode == SDL_SCANCODE_L && event.type == SDL_KEYUP)
		controls->move_low_up();
	if (event.key.keysym.scancode == SDL_SCANCODE_O && event.type == SDL_KEYUP)
		controls->move_high_down();
	if (event.key.keysym.scancode == SDL_SCANCODE_P && event.type == SDL_KEYUP)
		controls->move_high_up();
	if (event.key.keysym.scancode == SDL_SCANCODE_1 && event.type == SDL_KEYUP)
		controls->set_born(1);
	if (event.key.keysym.scancode == SDL_SCANCODE_2 && event.type == SDL_KEYUP)
		controls->set_born(2);
	if (event.key.keysym.scancode == SDL_SCANCODE_3 && event.type == SDL_KEYUP)
		controls->set_born(3);
	if (event.key.keysym.scancode == SDL_SCANCODE_4 && event.type == SDL_KEYUP)
		controls->set_born(4);
	if (event.key.keysym.scancode == SDL_SCANCODE_5 && event.type == SDL_KEYUP)
		controls->set_born(5);
	if (event.key.keysym.scancode == SDL_SCANCODE_6 && event.type == SDL_KEYUP)
		controls->set_born(6);
	if (event.key.keysym.scancode == SDL_SCANCODE_7 && event.type == SDL_KEYUP)
		controls->set_born(7);
	if (event.key.keysym.scancode == SDL_SCANCODE_8 && event.type == SDL_KEYUP)
		controls->set_born(8);
}
