#ifndef GRIDS_H
#define GRIDS_H

#define MAX_GRIDS_WIDTH 50
#define MAX_GRIDS_HEIGHT 50

typedef struct 
{
    int width;
    int height;
    int** grid;
} Grid;

void initializeGrid(Grid *grid, int width, int height);
void freeGrid(Grid *grid);
void isPositionValid(const Grid *grid, int x, int y);
void printGridInfo(const Grid *grid);
#endif // GRIDS_H