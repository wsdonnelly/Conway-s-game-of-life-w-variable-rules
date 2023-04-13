#ifndef CELL_MAP_HPP
#define CELL_MAP_HPP

#include <SDL.h>
#include <vector>
#include <cstdint>
#include "Controls.hpp"

const uint32_t OFF_COLOR = 0x00000000;
const uint32_t ON_COLOR = 0xD500F9FF;


const int MAP_SIZE = 500;
const int CELL_SIZE = 3;
const int SCREEN_SIZE = (MAP_SIZE * CELL_SIZE);

class CellMap {
	private:
		std::vector<uint8_t> cell_map;
		std::vector<uint8_t> cell_map_copy;

		void init_cell_map();
		void toggle_cell(int i);
		bool is_alive(int i);
		void set_neighbors(int i, bool kill);
		void DrawCell(SDL_Surface *screen, int x, int y, uint32_t color);
	public:
		CellMap();
		void evolve(SDL_Surface *screen, Controls &controls);
};

#endif

