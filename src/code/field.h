#ifndef FIELD_H
#define FIELD_H
#include "graphics.h"

typedef struct FieldItems
{
    Sprite *field_sprite;
} FieldItem;

typedef struct Fields
{
    short *field;
    short rows;
    short columns;
    short pitch_x;
    short pitch_y;
} Field;

short get_field_value(Field *field, short x, short y);

void set_field_value(Field *field, short x, short y, short value);

void initialize_field(Field *field, short rows, short columns, short pitch_x, short pitch_y);

void draw_field(Field *field, FieldItem *lookup_table, int center_x, int center_y);

#endif