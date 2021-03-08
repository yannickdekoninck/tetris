#include "graphics.h"
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

        draw_sprite(test_sprite, 1, 1);

        //Update the surface
        update_screen();
    }
    destroy_sprite(test_sprite);
    shut_down_graphics();
    return 0;
}