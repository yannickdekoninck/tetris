#include "SDL2/SDL.h"
#include "events.h"

void initialize_events()
{
    keyboard_event_counter = 0;
    keyboard_events = malloc(sizeof(int) * EVENTBUFFERSIZE);
}

bool get_events()
{
    SDL_Event e;
    bool quit;
    keyboard_event_counter = 0;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }

        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                keyboard_events[keyboard_event_counter].key = KEYUP;
                break;
            case SDLK_DOWN:
                keyboard_events[keyboard_event_counter].key = KEYDOWN;
                break;
            case SDLK_LEFT:
                keyboard_events[keyboard_event_counter].key = KEYLEFT;
                break;
            case SDLK_RIGHT:
                keyboard_events[keyboard_event_counter].key = KEYRIGHT;
                break;
            case SDLK_SPACE:
                keyboard_events[keyboard_event_counter].key = KEYSPACE;
                break;

            default:
                keyboard_event_counter--;
            }
            keyboard_event_counter++;
        }
    }
    return quit;
}