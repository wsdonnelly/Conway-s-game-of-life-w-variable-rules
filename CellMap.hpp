#ifndef CELL_MAP_HPP
#define CELL_MAP_HPP

#include <SDL.h>

#include "Controls.hpp"

const int OFF_COLOR = 0x00;
const int ON_COLOR = 0xff;


const int MAP_SIZE = 500;
const int CELL_SIZE = 3;
const int SCREEN_SIZE = (MAP_SIZE * CELL_SIZE);

//make constructor
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
		//friend class Controls;
		void evolve(SDL_Surface *screen, Controls &controls);
};

#endif