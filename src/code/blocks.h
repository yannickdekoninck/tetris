#ifndef BLOCKS_H
#define BLOCKS_H
#include "field.h"

#include "stdbool.h"

struct Coord
{
    int x;
    int y;
};
typedef struct Coord Coord;

typedef struct Blocks
{
    int orientations_count;
    Coord **orientations;

} Block;

typedef struct BlockInstance
{
    Coord position;
    int block_id;
    int orientation;
} BlockInstance;

void initialize_block_list();
void fill_block_instance(BlockInstance *block_instance, Field *field, Block *block_list, int value);

void rotate_block_instance(BlockInstance *block_instance, Block *block_list);
bool check_valid(Field *field, Coord *coord_list, int base_x, int base_y);
bool check_move(Field *field, BlockInstance *block_instance, int dx, int dy);
bool check_orientation(Field *field, BlockInstance *block_instance, int orientation);
Block *block_list;

#endif