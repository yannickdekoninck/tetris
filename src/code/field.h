#ifndef FIELD_H
#define FIELD_H
#include "graphics.h"

typedef struct FieldItems
{
    Sprite *field_sprite;
} FieldItem;

typedef struct Fields
{
    int *field;
    int rows;
    int columns;
    int pitch_x;
    int pitch_y;
} Field;

int get_field_value(Field *field, int x, int y);

void set_field_value(Field *field, int x, int y, int value);

void initialize_field(Field *field, int rows, int columns, int pitch_x, int pitch_y);

void draw_field(Field *field, FieldItem *lookup_table, int center_x, int center_y);

#endif