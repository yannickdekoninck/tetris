#include "SDL2/SDL.h"
#include "events.h"

bool get_events()
{
    SDL_Event e;
    bool quit;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }
    return quit;
}