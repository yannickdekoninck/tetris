#include "field.h"

void initialize_field(Field *field, int rows, int columns)
{
    short *new_field = malloc(sizeof(short) * rows * columns);
    field->field = new_field;
    field->rows = rows;
    field->columns = columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            new_field[i + j * rows] = -1;
        }
    }
    return;
}

void draw_field(Field *field, FieldItem *lookup_table, int center_x, int center_y)
{
    return;
}