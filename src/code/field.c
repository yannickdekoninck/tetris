#include "field.h"

short get_field_value(Field *field, short x, short y)
{
    return (field->field)[y + x * field->rows];
}

void set_field_value(Field *field, short x, short y, short value)
{
    (field->field)[y + x * field->rows] = value;
}

void initialize_field(Field *field, short rows, short columns, short pitch_x, short pitch_y)
{
    short *new_field = malloc(sizeof(short) * rows * columns);
    field->field = new_field;
    field->rows = rows;
    field->columns = columns;
    field->pitch_x = pitch_x;
    field->pitch_y = pitch_y;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            set_field_value(field, j, i, -1);
        }
    }
    return;
}

void draw_field(Field *field, FieldItem *lookup_table, int center_x, int center_y)
{
    int x_start = center_x - field->columns * field->pitch_x / 2;
    int y_start = center_y + field->rows * field->pitch_y / 2;

    short field_value;
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            field_value = get_field_value(field, j, i);
            if (field_value > -1)
            {
                int x = x_start + field->pitch_x * j;
                int y = y_start - field->pitch_y * i;
                draw_sprite(lookup_table[field_value].field_sprite, x, y);
            }
        }
    }

    return;
}