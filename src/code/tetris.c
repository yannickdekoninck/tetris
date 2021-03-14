#include "graphics.h"
#include "field.h"
#include "blocks.h"
#include "game_time.h"
#include "game.h"
#include "events.h"
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
    initialize_events();
    bool quit = false;
    Game *game = initialize_game();
    printf("Initialized game\n");

    while (!quit)
    {
        // getting events
        quit = get_events();

        // Updating game logic
        update_game(game);
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