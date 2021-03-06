#include "graphics.h"
#include "field.h"
#include "blocks.h"
#include "game_time.h"
#include "game.h"
#include "events.h"
#include "players.h"
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
    init_players();
    initialize_events();
    init_gametime(60);
    printf("Initialized game time\n");

    initialize_block_list();
    printf("Initialized block list\n");

    bool quit = false;
    int game_left_channel = 0;
    int game_right_channel = 0;

    Game **games;
    number_of_games = 1;

    if (number_of_joysticks == 0)
    {
        games = malloc(sizeof(Game *));
        games[0] = initialize_game(0);
    }
    else
    {
        number_of_games = number_of_joysticks;
        games = malloc(sizeof(Game *) * number_of_joysticks);
        for (int i = 0; i < number_of_games; i++)
        {
            games[i] = initialize_game(i + 1);
            int player_id = i;
            if (i >= number_of_players)
            {
                player_id = number_of_players - 1;
            }
            games[i]->player_id = player_id;
        }
    }
    printf("Initialized game\n");
    initialize_draw_context();
    printf("Initialized draw context\n");

    while (!quit)
    {
        // getting events
        quit = get_events();

        if (gamestate == STATE_STARTING)
        {
            bool ready = true;
            for (int i = 0; i < number_of_games; i++)
            {
                ready = ready & games[i]->ready;
            }
            if (ready)
            {
                gamestate = STATE_RUNNING;
            }
        }

        if (gamestate == STATE_RUNNING)
        {
            for (int i = 0; i < number_of_games; i++)
            {
                if (games[i]->total_lines == 50)
                {
                    games[i]->winner = true;
                    gamestate = STATE_FINISHED;
                    break;
                }
            }
        }

        // Updating game logic
        for (int i = 0; i < number_of_games; i++)
        {
            update_game(games[i]);
        }
        //Fill the surface white

        clear_screen();
        int dx = SCREEN_WIDTH / number_of_games;
        for (int i = 0; i < number_of_games; i++)
        {
            int game_x = i * dx + dx / 2;
            draw_game(games[i], game_x);
        }

        //Update the surface
        update_screen();
        tick();
    }
    // destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}