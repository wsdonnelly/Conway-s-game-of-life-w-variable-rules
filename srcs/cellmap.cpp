#include "CellMap.hpp"
#include <algorithm>

CellMap::CellMap(): cell_map(MAP_SIZE * MAP_SIZE, 0) {
	this->init_cell_map();
}

void CellMap::init_cell_map() {
	for (int i = 0; i < cell_map.size(); i++) {
		if (rand() % 100 < 3)
			toggle_cell(i);
	}
}

void CellMap::reset() {
	std::fill(cell_map.begin(), cell_map.end(), 0);
	init_cell_map();
}

void CellMap::evolve(SDL_Surface *screen, Controls &controls) {

	int num_neighbors;

	cell_map_copy = cell_map;
	for (int i = 0; i < cell_map.size(); i++) {
		if (cell_map_copy[i]) {
			num_neighbors = cell_map_copy[i] >> 1; 
			if (cell_map_copy[i] & 0x01) { //is alive
				if (num_neighbors < controls.low || num_neighbors > controls.high) {
					toggle_cell(i);
					DrawCell(screen, i % MAP_SIZE, i / MAP_SIZE, OFF_COLOR);
				}
			}
			else { //is dead
				if (num_neighbors == controls.born) {
					toggle_cell(i);
					DrawCell(screen, i % MAP_SIZE, i / MAP_SIZE, ON_COLOR);
				}
			}
		}
	}
}

//make all a single color
void CellMap::DrawCell(SDL_Surface *screen, int x, int y, uint32_t color)
{
	uint8_t *pixel_ptr = (uint8_t *)screen->pixels + (y * CELL_SIZE * SCREEN_SIZE + x * CELL_SIZE) * 4;

	for (int i = 0; i < CELL_SIZE; i++)
	{
		for (int j = 0; j < CELL_SIZE; j++)
		{
			*(pixel_ptr + j * 4 + 2) = color >> 24; //r
			*(pixel_ptr + j * 4 + 1) = color >> 16; //g
			*(pixel_ptr + j * 4) = color >> 8; //b
			// *(pixel_ptr + j * 4 + 2) = 0xAB; //r
			// *(pixel_ptr + j * 4 + 1) = 0x47; //g
			// *(pixel_ptr + j * 4) = 0xBC; //b
		}
		//go to next row
		pixel_ptr += SCREEN_SIZE * 4;
	}
}

void CellMap::toggle_cell(int i) {

	bool is_alive = cell_map[i] & 0x01;
	cell_map[i] ^= 0x01;
	update_neighbors(i, is_alive);
}

void CellMap::set_neighbors(int i, int sign) {

	cell_map[i + left] += (0x02 * sign);
	cell_map[i + right] += (0x02 * sign);
	cell_map[i + up] += (0x02 * sign);
	cell_map[i + down] += (0x02 * sign);
	cell_map[i + (up + left)] += (0x02 * sign);
	cell_map[i + (up + right)] += (0x02 * sign);
	cell_map[i + (down + left)] += (0x02 * sign);
	cell_map[i + (down + right)] += (0x02 * sign);
}

void CellMap::update_neighbors(int i, bool is_alive)
{
	left = (i % MAP_SIZE == 0) ? MAP_SIZE - 1 : - 1;
	right = (i % MAP_SIZE == MAP_SIZE - 1) ? -(MAP_SIZE - 1): 1;
	up = (i < MAP_SIZE) ? (MAP_SIZE * (MAP_SIZE - 1)) : -MAP_SIZE;
	down = (i / MAP_SIZE == MAP_SIZE - 1) ? -(MAP_SIZE * (MAP_SIZE - 1)) : MAP_SIZE;

	if (is_alive)
		set_neighbors(i, -1);
	else
		set_neighbors(i, 1);
}
