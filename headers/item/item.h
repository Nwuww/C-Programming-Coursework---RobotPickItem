#ifndef ITEM_H
#define ITEM_H

typedef enum { ITEM_OBSTACLE, ITEM_MARKER } ItemType;

typedef struct 
{
    int id;
    ItemType type;
    int position[2];
    int collected;
} Item;

// 方法签名
void initializeItem(Item* item, int id, ItemType type, int x, int y);
int isItemAtPosition(const Item* items, int itemCount, int x, int y);
void collectItem(Item* item);
void placeItemsRandomly(Item* items, int itemCount, const Grid* grid);

#endif // ITEM_H