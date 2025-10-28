#include "item.h"
#include "..\grids\grids.h"
#include <stdlib.h>

/// @brief Initialize an item with given parameters
/// @param item 
/// @param id 
/// @param type 
/// @param x 
/// @param y 
void initializeItem(Item *item, int id, ItemType type, int x, int y)
{
    item->id = id;
    item->type = type;
    item->position[0] = x;
    item->position[1] = y;
    item->collected = 0; // Item is not collected initially
}

/// @brief Check if an item is at a given position
/// @param item 
/// @param x 
/// @param y 
/// @return 
int isItemAtPosition(const Item item, int x, int y)
{
    return (item.position[0] == x && item.position[1] == y && !item.collected);
}

/// @brief collect the item
/// @param item 
void collectItem(Item *item)
{
    item->collected = 1;
}

/// @brief Place items randomly on the grid
/// @param items 
/// @param itemCount 
/// @param grid 
void placeItemsRandomly(Item *items, int itemCount, const Grid *grid)
{
    for (int i = 0; i < itemCount; i++)
    {
        int x, y;
        do
        {
            x = rand() % grid->width;
            y = rand() % grid->height;
        } while (grid->grid[y][x] != 0); // Ensure the position is empty

        items[i].position[0] = x;
        items[i].position[1] = y;
    }   
}
