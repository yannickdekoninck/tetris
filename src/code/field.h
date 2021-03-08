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
} Field;

void initialize_field(Field *field, int rows, int columns);

void draw_field(Field *field, FieldItem *lookup_table, int center_x, int center_y);

#endif