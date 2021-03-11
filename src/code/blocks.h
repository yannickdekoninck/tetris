#ifndef BLOCKS_H
#define BLOCKS_H
#include "field.h"

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

Block *initialize_block_list();
void fill_block_instance(BlockInstance *block_instance, Field *field, Block *block_list, int value);

#endif