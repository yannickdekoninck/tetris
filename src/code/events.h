#ifndef EVENT_H
#define EVENT_H

#include "stdbool.h"

#define KEYUP 100
#define KEYLEFT 101
#define KEYRIGHT 102
#define KEYDOWN 103
#define KEYSPACE 104

#define EVENTBUFFERSIZE 100

typedef struct InputEvent
{
    int key;
    bool key_down;
    int channel;

} InputEvent;

InputEvent *input_events;
int input_event_counter;

void initialize_events();

void initialize_gamepads();

bool get_events();

SDL_Joystick **gamepads;

#endif