#include "game_time.h"
#include <unistd.h>
#include <stdio.h>

void init_gametime(int refresh_rate)
{
    msec_per_frame = 1000 / refresh_rate;
    frame_counter = 0;
    last_time = SDL_GetTicks();
}

void tick()
{
    unsigned int current_time = SDL_GetTicks();
    int msec_to_wait = msec_per_frame - (current_time - last_time);
    if (msec_to_wait > 0)
    {
        SDL_Delay(msec_to_wait);
    }
    current_time = SDL_GetTicks();
    int frames_elapsed = (current_time - last_time) / msec_per_frame;
    last_time = current_time;
}