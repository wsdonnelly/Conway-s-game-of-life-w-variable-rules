#include "gol.hpp"

//make all a single color
inline void DrawCell(SDL_Surface *screen, int x, int y, uint32_t color)
{
	uint8_t *pixel_ptr = (uint8_t *)screen->pixels + (y * CELL_SIZE * SCREEN_SIZE + x * CELL_SIZE) * 4;

	for (int i = 0; i < CELL_SIZE; i++)
	{
		for (int j = 0; j < CELL_SIZE; j++)
		{
			*(pixel_ptr + j * 4) = color; //r
			*(pixel_ptr + j * 4 + 1) = color; //g
			*(pixel_ptr + j * 4 + 2) = color; //b
		}
		//go to next row
		pixel_ptr += SCREEN_SIZE * 4;
	}
}

bool CellMap::is_alive(unsigned int i) {
	return (map[i] & 0x01);
}

void CellMap::toggle_cell(unsigned int i)
{
	bool kill = is_alive(i);
	map[i] ^= 0x01;
	set_neighbors(i, kill);
}

void CellMap::set_neighbors(unsigned int i, bool kill)
{
	int up, left, right, down;

	left = (i % MAP_SIZE == 0) ? MAP_SIZE - 1 : - 1;
	right = (i % MAP_SIZE == MAP_SIZE - 1) ? -(MAP_SIZE - 1): 1;
	up = (i < MAP_SIZE) ? (MAP_SIZE * (MAP_SIZE - 1)) : -MAP_SIZE;
	down = (i / MAP_SIZE == MAP_SIZE - 1) ? -(MAP_SIZE * (MAP_SIZE - 1)) : MAP_SIZE;

	if (kill)
	{
		map[i + left] -= 0x02;
		map[i + right] -= 0x02;
		map[i + up] -= 0x02;
		map[i + down] -= 0x02;
		map[i + (up + left)] -= 0x02;
		map[i + (up + right)] -= 0x02;
		map[i + (down + left)] -= 0x02;
		map[i + (down + right)] -= 0x02;
	}
	else
	{
		map[i + left] += 0x02;
		map[i + right] += 0x02;
		map[i + up] += 0x02;
		map[i + down] += 0x02;
		map[i + (up + left)] += 0x02;
		map[i + (up + right)] += 0x02;
		map[i + (down + left)] += 0x02;
		map[i + (down + right)] += 0x02;
	}
}

void CellMap::init_map()
{
	srand(time(0));
	int i;

	for (i = 0; i < MAP_SIZE * MAP_SIZE; i++)
	{	
		
		if (rand() % 100 < 3)
			toggle_cell(i);
	}
}


void CellMap::evolve(SDL_Surface *screen, Controls &controls)
{
	unsigned int count;
	unsigned int size = MAP_SIZE * MAP_SIZE;
	
	memcpy(map_copy, map, size);
	for (unsigned int i = 0; i < size; i++)
	{
		if (map_copy[i])
		{
			count = map_copy[i] >> 1; 
			if (map_copy[i] & 0x01) //is alive
			{
				if (count < controls.low || count > controls.high)
				{
					toggle_cell(i);
					DrawCell(screen, i % MAP_SIZE, i / MAP_SIZE, OFF_COLOR);
				}
			}
			else //is dead
			{
				if (count == controls.born)
				{
					toggle_cell(i);
					DrawCell(screen, i % MAP_SIZE, i / MAP_SIZE, ON_COLOR);
				}
			}
		}
	}
}