#include "stdlib.h"
#include "blocks.h"

Block *initialize_block_list()
{

    Block *block_list = malloc(sizeof(Block) * 5);
    Coord **coords;
    // square
    coords = malloc(sizeof(Coord *) * 1);
    coords[0] = malloc(sizeof(Coord) * 4);
    coords[0][0].x = 0;
    coords[0][0].y = 0;
    coords[0][1].x = 1;
    coords[0][1].y = 0;
    coords[0][2].x = 0;
    coords[0][2].y = 1;
    coords[0][3].x = 1;
    coords[0][3].y = 1;
    block_list[0].orientations = coords;
    block_list[0].orientations_count = 1;

    // line
    coords = malloc(sizeof(Coord *) * 2);
    coords[0] = malloc(sizeof(Coord) * 4);
    coords[0][0].x = -1;
    coords[0][0].y = 0;
    coords[0][1].x = 0;
    coords[0][1].y = 0;
    coords[0][2].x = 1;
    coords[0][2].y = 0;
    coords[0][3].x = 2;
    coords[0][3].y = 0;
    coords[1] = malloc(sizeof(Coord) * 4);
    coords[1][0].x = 0;
    coords[1][0].y = -1;
    coords[1][1].x = 0;
    coords[1][1].y = 0;
    coords[1][2].x = 0;
    coords[1][2].y = 1;
    coords[1][3].x = 0;
    coords[1][3].y = 2;
    block_list[1].orientations = coords;
    block_list[1].orientations_count = 2;

    // Triangle
    coords = malloc(sizeof(Coord *) * 4);
    coords[0] = malloc(sizeof(Coord) * 4);
    coords[0][0].x = -1;
    coords[0][0].y = 0;
    coords[0][1].x = 0;
    coords[0][1].y = 0;
    coords[0][2].x = 1;
    coords[0][2].y = 0;
    coords[0][3].x = 0;
    coords[0][3].y = 1;
    coords[1] = malloc(sizeof(Coord) * 4);
    coords[1][0].x = 0;
    coords[1][0].y = -1;
    coords[1][1].x = 0;
    coords[1][1].y = 0;
    coords[1][2].x = 0;
    coords[1][2].y = 1;
    coords[1][3].x = 1;
    coords[1][3].y = 0;
    coords[2] = malloc(sizeof(Coord) * 4);
    coords[2][0].x = -1;
    coords[2][0].y = 0;
    coords[2][1].x = 0;
    coords[2][1].y = 0;
    coords[2][2].x = 1;
    coords[2][2].y = 0;
    coords[2][3].x = 0;
    coords[2][3].y = -1;
    coords[3] = malloc(sizeof(Coord) * 4);
    coords[3][0].x = 0;
    coords[3][0].y = -1;
    coords[3][1].x = 0;
    coords[3][1].y = 0;
    coords[3][2].x = 0;
    coords[3][2].y = 1;
    coords[3][3].x = -1;
    coords[3][3].y = 0;
    block_list[2].orientations = coords;
    block_list[2].orientations_count = 4;

    // Right L
    coords = malloc(sizeof(Coord *) * 4);
    coords[0] = malloc(sizeof(Coord) * 4);
    coords[0][0].x = 0;
    coords[0][0].y = 2;
    coords[0][1].x = 0;
    coords[0][1].y = 1;
    coords[0][2].x = 0;
    coords[0][2].y = 0;
    coords[0][3].x = 1;
    coords[0][3].y = 0;
    coords[1] = malloc(sizeof(Coord) * 4);
    coords[1][0].x = 2;
    coords[1][0].y = 0;
    coords[1][1].x = 1;
    coords[1][1].y = 0;
    coords[1][2].x = 0;
    coords[1][2].y = 0;
    coords[1][3].x = 0;
    coords[1][3].y = -1;
    coords[2] = malloc(sizeof(Coord) * 4);
    coords[2][0].x = 0;
    coords[2][0].y = -2;
    coords[2][1].x = 0;
    coords[2][1].y = -1;
    coords[2][2].x = 0;
    coords[2][2].y = 0;
    coords[2][3].x = -1;
    coords[2][3].y = 0;
    coords[3] = malloc(sizeof(Coord) * 4);
    coords[3][0].x = -2;
    coords[3][0].y = 0;
    coords[3][1].x = -1;
    coords[3][1].y = 0;
    coords[3][2].x = 0;
    coords[3][2].y = 0;
    coords[3][3].x = 0;
    coords[3][3].y = 1;
    block_list[3].orientations = coords;
    block_list[3].orientations_count = 4;

    // Left L
    coords = malloc(sizeof(Coord *) * 4);
    coords[0] = malloc(sizeof(Coord) * 4);
    coords[0][0].x = 0;
    coords[0][0].y = 2;
    coords[0][1].x = 0;
    coords[0][1].y = 1;
    coords[0][2].x = 0;
    coords[0][2].y = 0;
    coords[0][3].x = -1;
    coords[0][3].y = 0;
    coords[1] = malloc(sizeof(Coord) * 4);
    coords[1][0].x = 2;
    coords[1][0].y = 0;
    coords[1][1].x = 1;
    coords[1][1].y = 0;
    coords[1][2].x = 0;
    coords[1][2].y = 0;
    coords[1][3].x = 0;
    coords[1][3].y = 1;
    coords[2] = malloc(sizeof(Coord) * 4);
    coords[2][0].x = 0;
    coords[2][0].y = -2;
    coords[2][1].x = 0;
    coords[2][1].y = -1;
    coords[2][2].x = 0;
    coords[2][2].y = 0;
    coords[2][3].x = 1;
    coords[2][3].y = 0;
    coords[3] = malloc(sizeof(Coord) * 4);
    coords[3][0].x = -2;
    coords[3][0].y = 0;
    coords[3][1].x = -1;
    coords[3][1].y = 0;
    coords[3][2].x = 0;
    coords[3][2].y = 0;
    coords[3][3].x = 0;
    coords[3][3].y = -1;
    block_list[4].orientations = coords;
    block_list[4].orientations_count = 4;

    return block_list;
}

void fill_block_instance(BlockInstance *block_instance, Field *field, Block *block_list, int value)
{
    int start_x = block_instance->position.x;
    int start_y = block_instance->position.y;

    for (int i = 0; i < 4; i++)
    {
        Coord c = block_list[block_instance->block_id].orientations[block_instance->orientation][i];
        int current_x = start_x + c.x;
        int current_y = start_y + c.y;
        set_field_value(field, current_x, current_y, value);
    }
}

void rotate_block_instance(BlockInstance *block_instance, Block *block_list)
{
    int new_orientation = (block_instance->orientation + 1) % block_list[block_instance->block_id].orientations_count;
    block_instance->orientation = new_orientation;
}