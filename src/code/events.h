#ifndef EVENT_H
#include "stdbool.h"
#define EVENT_H
typedef struct KeyboardEvent
{
    char key;
    bool key_down;

} KeyboardEvent;

bool get_events();

#endif