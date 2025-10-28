#include "grids.h"
#include <stdlib.h>
#include <stdio.h>

/// @brief initialize the grid with given width and height
/// @param grid 
/// @param width 
/// @param height 
void initializeGrid(Grid *grid, int width, int height)
{
    if (width > MAX_GRIDS_WIDTH) width = MAX_GRIDS_WIDTH;
    if (height > MAX_GRIDS_HEIGHT) height = MAX_GRIDS_HEIGHT;

    grid->width = width;
    grid->height = height;
}

/// @brief free the allocated memory for the grid
/// @param grid 
void freeGrid(Grid *grid)
{
    for (int i = 0; i < grid->height; i++)
    {
        free(grid->grid[i]);
    }
    free(grid->grid);
}

/// @brief check if the given position is valid within the grid
/// @param grid 
/// @param x 
/// @param y 
void checkValid(const Grid *grid, int x, int y)
{
    return (x >= 0 && x < grid->width && y >= 0 && y < grid->height);
}

/// @brief print grid information
/// @param grid 
void printGridInfo(const Grid *grid)
{
    printf("Grid Width: %d, Height: %d\n", grid->width, grid->height);
}
