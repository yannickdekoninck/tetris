#include "graphics.h"
#include "field.h"
#include "blocks.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{

    int gfx_init = initialize_graphics("Tetris", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (gfx_init < 0)
    {
        printf("Something went wrong initializing the graphics system");
        return -1;
    }

    bool quit = false;
    Sprite *test_sprite = create_sprite("assets/tile.png");
    Field field;
    initialize_field(&field, 22, 10, test_sprite->width + 1, test_sprite->height + 1);

    Field current_block_field;
    initialize_field(&current_block_field, 22, 10, test_sprite->width + 1, test_sprite->height + 1);

    set_field_value(&field, 0, 0, 0);
    set_field_value(&field, 9, 0, 0);
    set_field_value(&field, 0, 21, 0);
    set_field_value(&field, 9, 21, 0);

    Block *block_list = initialize_block_list();
    BlockInstance current_block;
    current_block.block_id = 1;
    current_block.orientation = 1;
    Coord current_position;
    current_position.x = 5;
    current_position.y = 6;
    current_block.position = current_position;

    fill_block_instance(&current_block, &current_block_field, block_list, 0);

    FieldItem item0;
    item0.field_sprite = test_sprite;
    FieldItem lookup_table[1];
    lookup_table[0] = item0;

    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        //Fill the surface white
        clear_screen();
        draw_field(&field, lookup_table, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        draw_field(&current_block_field, lookup_table, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

        //Update the surface
        update_screen();
    }
    destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}