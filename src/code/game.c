#include "game.h"

Game *initialize_game()
{
    Game *new_game = malloc(sizeof(Game));
    new_game->game_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH);
    new_game->current_block_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH);
    new_game->current_block = malloc(sizeof(BlockInstance));
    new_game->current_block->block_id = 0;
    new_game->current_block->orientation = 0;
    Coord initial_position = {.x = 5, .y = 10};
    new_game->current_block->position = initial_position;

    // L
    set_field_value(new_game->game_field, 0, 0, 0);
    set_field_value(new_game->game_field, 1, 0, 0);
    set_field_value(new_game->game_field, 0, 1, 0);
    set_field_value(new_game->game_field, 0, 2, 0);

    // I
    set_field_value(new_game->game_field, 3, 0, 0);
    set_field_value(new_game->game_field, 3, 1, 0);
    set_field_value(new_game->game_field, 3, 2, 0);

    // V
    set_field_value(new_game->game_field, 5, 2, 0);
    set_field_value(new_game->game_field, 5, 1, 0);
    set_field_value(new_game->game_field, 6, 0, 0);
    set_field_value(new_game->game_field, 7, 1, 0);
    set_field_value(new_game->game_field, 7, 2, 0);

    // J

    set_field_value(new_game->game_field, 0, 4, 0);
    set_field_value(new_game->game_field, 1, 5, 0);
    set_field_value(new_game->game_field, 1, 6, 0);

    // U

    set_field_value(new_game->game_field, 3, 6, 0);
    set_field_value(new_game->game_field, 3, 5, 0);
    set_field_value(new_game->game_field, 3, 4, 0);
    set_field_value(new_game->game_field, 4, 4, 0);
    set_field_value(new_game->game_field, 5, 4, 0);
    set_field_value(new_game->game_field, 5, 5, 0);
    set_field_value(new_game->game_field, 5, 6, 0);

    // L

    set_field_value(new_game->game_field, 7, 6, 0);
    set_field_value(new_game->game_field, 7, 5, 0);
    set_field_value(new_game->game_field, 7, 4, 0);
    set_field_value(new_game->game_field, 8, 4, 0);

    // E

    set_field_value(new_game->game_field, 10, 4, 0);
    set_field_value(new_game->game_field, 10, 5, 0);
    set_field_value(new_game->game_field, 10, 6, 0);
    set_field_value(new_game->game_field, 10, 7, 0);
    set_field_value(new_game->game_field, 10, 3, 0);
    set_field_value(new_game->game_field, 11, 7, 0);
    set_field_value(new_game->game_field, 11, 5, 0);
    set_field_value(new_game->game_field, 11, 3, 0);

    return new_game;
}

void update_game(Game *game)
{

    if ((frame_counter % 60) == 0)
    {
        fill_block_instance(game->current_block, game->game_field, block_list, -1);
        rotate_block_instance(game->current_block, block_list);
        fill_block_instance(game->current_block, game->game_field, block_list, 0);
    }

    if ((frame_counter % 240) == 0)
    {
        fill_block_instance(game->current_block, game->game_field, block_list, -1);
        game->current_block->block_id = (game->current_block->block_id + 1) % 5;
        game->current_block->orientation = 0;
        fill_block_instance(game->current_block, game->game_field, block_list, 0);
    }

    // See if it's time to move down

    // if so -> do this first

    // Check if that will finish the line
}

void draw_game(Game *game)
{
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