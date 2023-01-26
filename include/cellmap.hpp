#ifndef CELL_MAP_HPP
#define CELL_MAP_HPP

#include <SDL.h>
#include "controls.hpp"

const uint32_t OFF_COLOR = 0x00000000;
const uint32_t ON_COLOR = 0xD500F9FF;


const int MAP_SIZE = 500;
const int CELL_SIZE = 3;
const int SCREEN_SIZE = (MAP_SIZE * CELL_SIZE);

class CellMap {
	private:
		uint8_t map[MAP_SIZE * MAP_SIZE] = {0};
		uint8_t map_copy[MAP_SIZE * MAP_SIZE];
		void DrawCell(SDL_Surface *screen, int x, int y, uint32_t color);
		bool is_alive(unsigned int i);
		void toggle_cell(unsigned int i);
		void set_neighbors(unsigned int i, bool kill);
		
	public:
		CellMap();
		void init_map();
		void evolve(SDL_Surface *screen, Controls &controls);
};

#endif

