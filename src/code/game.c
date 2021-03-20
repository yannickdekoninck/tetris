#include "game.h"
#include "events.h"

Game *initialize_game()
{
    // Memory allocation
    Game *new_game = malloc(sizeof(Game));
    new_game->game_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH);
    new_game->current_block_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH);

    // Initialize the block sequence
    new_game->block_sequence = malloc(sizeof(int) * MAX_BLOCKS);
    srand(time(NULL));
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        new_game->block_sequence[i] = rand() % 5;
    }

    new_game->sequence_id = 0;

    new_game->current_block = malloc(sizeof(BlockInstance));

    new_game->total_lines = 0;

    // L
    set_field_value(new_game->game_field, 0, 0, 0);
    set_field_value(new_game->game_field, 9, 0, 0);

    next_block(new_game);

    return new_game;
}
bool move_current_block(Game *game, int dx, int dy)
{
    if (check_move(game->game_field, game->current_block, dx, dy))
    {
        fill_block_instance(game->current_block, game->current_block_field, block_list, -1);
        game->current_block->position.x += dx;
        game->current_block->position.y += dy;
        fill_block_instance(game->current_block, game->current_block_field, block_list, 0);
        return true;
    }
    return false;
}

void rotate_current_block(Game *game)
{
    int next_orientation = (game->current_block->orientation + 1) % (block_list[game->current_block->block_id].orientations_count);
    if (check_orientation(game->game_field, game->current_block, next_orientation))
    {
        fill_block_instance(game->current_block, game->current_block_field, block_list, -1);
        rotate_block_instance(game->current_block, block_list);
        fill_block_instance(game->current_block, game->current_block_field, block_list, 0);
    }
}

void drop_current_block(Game *game)
{
    while (move_current_block(game, 0, -1))
    {
    }

    block_down(game);
}

void next_block(Game *game)
{
    game->current_block->block_id = game->block_sequence[game->sequence_id];
    game->current_block->orientation = 0;
    Coord initial_position = {.x = 4, .y = 19};
    game->current_block->position = initial_position;
    fill_block_instance(game->current_block, game->current_block_field, block_list, 0);
}

void block_down(Game *game)
{
    fill_block_instance(game->current_block, game->game_field, block_list, 0);
    fill_block_instance(game->current_block, game->current_block_field, block_list, -1);
    check_lines(game);
    game->sequence_id++;
    next_block(game);
}

void check_lines(Game *game)
{
    // loop over rows
    for (int i = 0; i < game->game_field->rows; i++)
    {
        bool all_filled = true;

        for (int j = 0; j < game->game_field->columns; j++)
        {
            int value = get_field_value(game->game_field, j, i);
            if (value < 0)
            {
                all_filled = false;
            }
        }
        if (all_filled)
        {
            // Line!!
            game->total_lines++;
            printf("We have %d lines!\n", game->total_lines);
            for (int ii = i + 1; ii < game->game_field->rows; ii++)
            {
                for (int j = 0; j < game->game_field->columns; j++)
                {
                    int new_value = get_field_value(game->game_field, j, ii);
                    set_field_value(game->game_field, j, ii - 1, new_value);
                }
            }
            // clean up top line

            for (int j = 0; j < game->game_field->columns; j++)
            {
                set_field_value(game->game_field, j, game->game_field->rows - 1, -1);
            }
            i = -1;
        }
    }
}

void update_game(Game *game)
{

    // Auto move
    if ((frame_counter % 60) == 0)
    {

        fill_block_instance(game->current_block, game->current_block_field, block_list, -1);
        if (check_move(game->game_field, game->current_block, 0, -1))
        {
            game->current_block->position.y -= 1;
            fill_block_instance(game->current_block, game->current_block_field, block_list, 0);
        }
        else
        {
            block_down(game);
        }
    }
    // Event checking

    for (int i = 0; i < input_event_counter; i++)
    {
        InputEvent e = input_events[i];
        switch (e.key)
        {
        case KEYLEFT:
            move_current_block(game, -1, 0);
            break;
        case KEYRIGHT:
            move_current_block(game, +1, 0);
            break;
        case KEYDOWN:
            move_current_block(game, 0, -1);
            break;
        case KEYUP:
            rotate_current_block(game);
            break;
        case KEYSPACE:
            drop_current_block(game);
            break;
        default:
            break;
        }
    }

    // See if it's time to move down

    // if so -> do this first

    // Check if that will finish the line
}

void draw_game(Game *game, int draw_x)
{
    draw_field(game->current_block_field, field_draw_context, draw_x, 300);
    draw_field(game->game_field, field_draw_context, draw_x, 300);
    return;
}

void initialize_draw_context()
{
    Sprite *tile = create_sprite("assets/tile.png");
    FieldItem *item0 = malloc(sizeof(FieldItem));
    item0->field_sprite = tile;
    FieldItem *lookup_table = malloc(sizeof(FieldItem) * 1);
    lookup_table = item0;

    field_draw_context = malloc(sizeof(FieldDrawContext));
    field_draw_context->lookup_table = lookup_table;
    field_draw_context->pitch_x = tile->width + 1;
    field_draw_context->pitch_y = tile->height + 1;
}