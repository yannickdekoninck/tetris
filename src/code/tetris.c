#include "graphics.h"
#include "field.h"
#include "blocks.h"
#include "game_time.h"
#include "game.h"
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
    init_gametime(60);
    initialize_draw_context();
    printf("Initialized draw context\n");
    initialize_block_list();
    printf("Initialized block list\n");
    bool quit = false;
    Game *game = initialize_game();
    printf("Initialized game\n");

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
        update_game(game);
        printf("Updated game\n");
        //Fill the surface white
        clear_screen();

        draw_game(game);

        //Update the surface
        update_screen();
        tick();
    }
    // destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}