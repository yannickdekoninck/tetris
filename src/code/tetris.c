#include "graphics.h"
#include "field.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{

    int gfx_init = initialize_graphics("SDL tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (gfx_init < 0)
    {
        printf("Something went wrong initializing the graphics system");
        return -1;
    }

    bool quit = false;
    Sprite *test_sprite = create_sprite("assets/tile.png");
    Field field;
    initialize_field(&field, 22, 10, test_sprite->width + 1, test_sprite->height + 1);
    set_field_value(&field, 0, 0, 0);
    set_field_value(&field, 1, 0, 0);
    set_field_value(&field, 1, 1, 0);
    set_field_value(&field, 2, 0, 0);

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
        int rows = 40;
        int columns = 10;
        int start_x = SCREEN_WIDTH / 2 - columns * test_sprite->width / 2;
        int start_y = SCREEN_HEIGHT - test_sprite->height - 20;
        int pitch_x = test_sprite->width + 1;
        int pitch_y = test_sprite->height + 1;
        int x = 0;
        int y = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                x = start_x + i * pitch_x;
                y = start_y - j * pitch_y;
                //draw_sprite(test_sprite, x, y);
            }
        }

        //Update the surface
        update_screen();
    }
    destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}