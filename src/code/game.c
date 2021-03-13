#include "game.h"

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
    new_game->current_block->block_id = new_game->block_sequence[0];
    new_game->current_block->orientation = 0;
    Coord initial_position = {.x = 4, .y = 19};
    new_game->current_block->position = initial_position;

    // L
    set_field_value(new_game->game_field, 0, 0, 0);
    set_field_value(new_game->game_field, 9, 0, 0);
    set_field_value(new_game->game_field, 9, 21, 0);
    set_field_value(new_game->game_field, 0, 21, 0);

    return new_game;
}

void update_game(Game *game)
{

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
            fill_block_instance(game->current_block, game->game_field, block_list, 0);
            game->sequence_id++;
            game->current_block->orientation = 0;
            Coord initial_position = {.x = 4, .y = 19};
            game->current_block->position = initial_position;
            game->current_block->block_id = game->block_sequence[game->sequence_id];
            fill_block_instance(game->current_block, game->current_block_field, block_list, 0);
        }
    }

    // See if it's time to move down

    // if so -> do this first

    // Check if that will finish the line
}

void draw_game(Game *game)
{
    draw_field(game->current_block_field, field_draw_context, 400, 300);
    draw_field(game->game_field, field_draw_context, 400, 300);
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