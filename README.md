# Conway's Game of Life
## includes variable rule set
- Conway's original requires 2 or 3 neighbors to stay alive
- and exactlly 3 neighbors for a dead cell to be 'born'
- In my version you can adjust the range of required neighbors to remain alive
- and set the specific number of neighbors (1 - 8) for a dead cell to be born
## requires SDl2 libray installed

For the time being this requires that you update the appropriate paths in the Makefile to link to your local copy of SDL2:
- LIB_INCLUDE
- LIB 

## controls
- move the window so you can also see your terminal
- 'k' and 'l' will move the low range up and down. 'o' and 'p' will move the high range up and down.
- eg. the game starts with the range to stay alive between 2 and 3. 
- so a range of 1-3 maeans anything less than 1 (0) or anything greater than (3) will die on the subsequent round
- numbers 1 - 8 will select the number of neighbors in order for a new cell to be born.
- r reseeds the board
