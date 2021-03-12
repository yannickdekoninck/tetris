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

    return new_game;
}

void update_game(Game *game)
{

    /*
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
    */

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
    FieldItem item0;
    item0.field_sprite = tile;
    FieldItem lookup_table[1];
    lookup_table[0] = item0;

    field_draw_context = malloc(sizeof(FieldDrawContext));
    field_draw_context->lookup_table = lookup_table;
    field_draw_context->pitch_x = tile->width + 1;
    field_draw_context->pitch_y = tile->height + 1;
}