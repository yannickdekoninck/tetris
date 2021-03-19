#ifndef EVENT_H
#define EVENT_H

#include "stdbool.h"

#define KEYUP 100
#define KEYLEFT 101
#define KEYRIGHT 102
#define KEYDOWN 103
#define KEYSPACE 104

#define EVENTBUFFERSIZE 100

typedef struct KeyboardEvent
{
    int key;
    bool key_down;

} KeyboardEvent;

KeyboardEvent *keyboard_events;
int keyboard_event_counter;

void initialize_events();

bool get_events();

#endif