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

typedef struct FieldDrawContext
{
    FieldItem *lookup_table;
    int pitch_x;
    int pitch_y;

} FieldDrawContext;

int get_field_value(Field *field, int x, int y);

void set_field_value(Field *field, int x, int y, int value);

Field *initialize_field(int rows, int columns);

void draw_field(Field *field, FieldDrawContext *drawing_context, int center_x, int center_y);

#endif