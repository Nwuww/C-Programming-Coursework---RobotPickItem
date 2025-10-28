#ifndef GRIDS_H
#define GRIDS_H

#define MAX_GRIDS_WIDTH 50
#define MAX_GRIDS_HEIGHT 50

typedef struct 
{
    int width;
    int height;
    int** grid; // 0:empty, 1:obstacle, 2:marker
} Grid;

void initializeGrid(Grid *grid, int width, int height);
void freeGrid(Grid *grid);
void checkValid(const Grid *grid, int x, int y);
void printGridInfo(const Grid *grid);
#endif // GRIDS_H