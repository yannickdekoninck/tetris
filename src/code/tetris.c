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
    int game_left_channel = 0;
    int game_right_channel = 0;

    if (number_of_joysticks == 1)
    {
        game_left_channel = 1;
    }
    if (number_of_joysticks == 2)
    {
        game_left_channel = 1;
        game_right_channel = 2;
    }

    Game *game_left = initialize_game(game_left_channel);
    Game *game_right = initialize_game(game_right_channel);
    printf("Initialized game\n");

    while (!quit)
    {
        // getting events
        quit = get_events();

        // Updating game logic
        update_game(game_left);
        update_game(game_right);
        //Fill the surface white

        clear_screen();
        draw_game(game_left, 230);
        draw_game(game_right, 580);

        //Update the surface
        update_screen();
        tick();
    }
    // destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}