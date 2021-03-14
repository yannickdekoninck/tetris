#include "field.h"

int get_field_value(Field *field, int x, int y)
{
    return (field->field)[y + x * field->rows];
}

void set_field_value(Field *field, int x, int y, int value)
{
    if ((x >= 0) & (x < field->columns) & (y >= 0) & (y < field->rows))
    {
        (field->field)[y + x * field->rows] = value;
        return;
    }
    printf("Tried to set field value to (%d, %d) but field size is (%d, %d)", x, y, field->columns, field->rows);
    return;
}

Field *initialize_field(int rows, int columns)
{
    Field *field = malloc(sizeof(Field));
    int *new_field = malloc(sizeof(int) * rows * columns);
    field->field = new_field;
    field->rows = rows;
    field->columns = columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            set_field_value(field, j, i, -1);
        }
    }
    return field;
}

void draw_field(Field *field, FieldDrawContext *field_draw_context, int center_x, int center_y)
{
    int x_start = center_x - field->columns * field_draw_context->pitch_x / 2;
    int y_start = center_y + field->rows * field_draw_context->pitch_y / 2;

    int field_value;
    for (int i = 0; i < field->rows; i++)
    {
        for (int j = 0; j < field->columns; j++)
        {
            field_value = get_field_value(field, j, i);
            if (field_value > -1)
            {
                int x = x_start + field_draw_context->pitch_x * j;
                int y = y_start - field_draw_context->pitch_y * i;
                draw_sprite(field_draw_context->lookup_table[field_value].field_sprite, x, y);
            }
        }
    }

    return;
}
