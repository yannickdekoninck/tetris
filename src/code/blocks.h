#ifndef BLOCKS_H
#define BLOCKS_H

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

#endif