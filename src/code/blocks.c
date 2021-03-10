#include "stdlib.h"
#include "blocks.h"

Block *initialize_block_list()
{

    Block *block_list = malloc(sizeof(Block) * 5);

    // square
    Coord **coords0 = malloc(sizeof(Coord *) * 1);
    coords0[0] = malloc(sizeof(Coord) * 4);
    coords0[0][0].x = 0;
    coords0[0][0].y = 0;
    coords0[0][1].x = 1;
    coords0[0][1].y = 0;
    coords0[0][2].x = 0;
    coords0[0][2].y = 1;
    coords0[0][3].x = 1;
    coords0[0][3].y = 1;
    block_list[0].orientations = coords0;
    block_list[0].orientations_count = 1;

    // line
    Coord **coords1 = malloc(sizeof(Coord *) * 2);
    coords1[0] = malloc(sizeof(Coord) * 4);
    coords1[0][0].x = -1;
    coords1[0][0].y = 0;
    coords1[0][1].x = 0;
    coords1[0][1].y = 0;
    coords1[0][2].x = 1;
    coords1[0][2].y = 0;
    coords1[0][3].x = 2;
    coords1[0][3].y = 0;
    coords1[1] = malloc(sizeof(Coord) * 4);
    coords1[1][0].x = 0;
    coords1[1][0].y = -1;
    coords1[1][1].x = 0;
    coords1[1][1].y = 0;
    coords1[1][2].x = 0;
    coords1[1][2].y = 1;
    coords1[1][3].x = 0;
    coords1[1][3].y = 2;
    block_list[1].orientations = coords1;
    block_list[1].orientations_count = 2;

    return block_list;
}
