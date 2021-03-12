#ifndef GAMETIME_H
#define GAMETIME_H
#include "SDL2/SDL.h"
int frame_counter;
unsigned int last_time;
int msec_per_frame;

void init_gametime(int refresh_rate);

int get_frame_count();

void tick();

#endif