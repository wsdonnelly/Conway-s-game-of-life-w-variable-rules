#ifndef GOL_HPP
#define GOL_HPP

#include <SDL.h>
#include <ctime>
#include <iostream>

const int OFF_COLOR = 0x00;
const int ON_COLOR = 0xff;


const int MAP_SIZE = 500;
const int CELL_SIZE = 3;
const int SCREEN_SIZE = (MAP_SIZE * CELL_SIZE);

class Controls {
	public:
		unsigned int low = 2;
		unsigned int high = 3;
		unsigned int born = 3;
		void move_low_down();
		void move_low_up();
		void move_high_up();
		void move_high_down();
		void set_born(int n);
		void display();
};

class CellMap {
	private:
		uint8_t map[MAP_SIZE * MAP_SIZE] = {0};
		uint8_t map_copy[MAP_SIZE * MAP_SIZE];
	public:
		void init_map();
		bool is_alive(unsigned int i);
		void toggle_cell(unsigned int i);
		void set_neighbors(unsigned int i, bool kill);
		void evolve(SDL_Surface *screen, Controls &controls);
};


inline void DrawCell(SDL_Surface *screen, int x, int y, int s_width, uint32_t color);
void event_handler(SDL_Event event, CellMap *map, Controls *controls, bool *quit);

#endif