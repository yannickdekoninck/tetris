#include "game.h"
#include "events.h"
#include "players.h"

Game *initialize_game(int input_channel)
{

    // Memory allocation
    Game *new_game = malloc(sizeof(Game));
    new_game->game_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH, -1);
    new_game->current_block_field = initialize_field(FIELD_HEIGHT, FIELD_WIDTH, -2);

    new_game->input_channel = input_channel;

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

    next_block(new_game);

    gamestate = STATE_STARTING;

    new_game->ready = false;
    new_game->winner = false;

    return new_game;
}
bool move_current_block(Game *game, int dx, int dy)
{
    if (check_move(game->game_field, game->current_block, dx, dy))
    {
        fill_block_instance(game->current_block, game->current_block_field, block_list, -2);
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
            printf("[Channel %d] We have %d lines!\n", game->input_channel, game->total_lines);
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

int calculate_next_player_id(int current_id, int change)
{
    int next_id = current_id + change;
    if (next_id < 0)
    {
        next_id = number_of_players - 1;
    }
    if (next_id >= number_of_players)
    {
        next_id = 0;
    }
    return next_id;
}

void update_game(Game *game)
{

    if (gamestate == STATE_STARTING)
    {
        for (int i = 0; i < input_event_counter; i++)
        {
            InputEvent e = input_events[i];
            if (e.channel == game->input_channel)
            {
                switch (e.key)
                {
                case KEYDOWN:
                    if (game->ready == false)
                    {
                        game->player_id = calculate_next_player_id(game->player_id, -1);
                    }
                    break;
                case KEYUP:
                    if (game->ready == false)
                    {
                        game->player_id = calculate_next_player_id(game->player_id, 1);
                    }
                    break;
                case KEYSPACE:
                    game->ready = !game->ready;
                    break;
                default:
                    break;
                }
            }
        }
    }

    if (gamestate == STATE_RUNNING)
    {
        // Auto move
        if ((frame_counter % 60) == 0)
        {

            fill_block_instance(game->current_block, game->current_block_field, block_list, -2);
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
            if (e.channel == game->input_channel)
            {
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
        }
    }

    // See if it's time to move down

    // if so -> do this first

    // Check if that will finish the line
}

void draw_game(Game *game, int draw_x)
{
    if (gamestate == STATE_RUNNING)
    {
        //draw_field(game->current_block_field, field_draw_context, draw_x, 300);
        Field *field_to_draw = merge_fields(game->current_block_field, game->game_field);
        draw_field(field_to_draw, field_draw_context[game->input_channel - 1], draw_x, 300);
        char *score = malloc(sizeof(char) * 5);
        sprintf(score, "%d", game->total_lines);
        Color text_color = COLOR_BLUE;
        draw_text(score, draw_x, 525, text_color);
        draw_text(players[game->player_id], draw_x, 100, text_color);
    }
    if ((gamestate == STATE_FINISHED) && game->winner)
    {
        //draw_field(game->current_block_field, field_draw_context, draw_x, 300);
        Field *field_to_draw = merge_fields(game->current_block_field, game->game_field);
        draw_field(field_to_draw, field_draw_context[game->input_channel - 1], draw_x, 300);
        char *score = malloc(sizeof(char) * 5);
        sprintf(score, "%d", game->total_lines);
        Color text_color = COLOR_GREEN;
        draw_text(score, draw_x, 525, text_color);
        draw_text(players[game->player_id], draw_x, 100, text_color);
    }
    if (gamestate == STATE_STARTING)
    {
        if (game->ready)
        {
            Color text_color = COLOR_GREEN;
            draw_text(players[game->player_id], draw_x, 300, text_color);
        }
        else
        {
            Color text_color = COLOR_BLUE;
            draw_text(players[game->player_id], draw_x, 300, text_color);
        }
    }
    return;
}

void initialize_draw_context()
{
    char **dark_tiles = malloc(sizeof(char *) * 4);
    char **light_tiles = malloc(sizeof(char *) * 4);
    dark_tiles[0] = "assets/tile_dark.png";
    dark_tiles[2] = "assets/tile_dark_brown.png";
    dark_tiles[1] = "assets/tile_dark_blue.png";
    dark_tiles[3] = "assets/tile_dark_green.png";
    light_tiles[0] = "assets/tile_light.png";
    light_tiles[2] = "assets/tile_light_brown.png";
    light_tiles[1] = "assets/tile_light_blue.png";
    light_tiles[3] = "assets/tile_light_green.png";
    field_draw_context = malloc(sizeof(FieldDrawContext *) * number_of_games);
    for (int i = 0; i < number_of_games; i++)
    {
        field_draw_context[i] = malloc(sizeof(FieldDrawContext));
        printf("About to initialize fraw context");
        Sprite *tile_light = create_sprite(light_tiles[i]);
        Sprite *tile_dark = create_sprite(dark_tiles[i]);
        FieldItem *item0 = malloc(sizeof(FieldItem));
        item0->field_sprite = tile_light;
        FieldItem *item1 = malloc(sizeof(FieldItem));
        item1->field_sprite = tile_dark;
        FieldItem **lookup_table = malloc(sizeof(FieldItem *) * 2);
        lookup_table[0] = item0;
        lookup_table[1] = item1;
        field_draw_context[i]->lookup_table = lookup_table;
        field_draw_context[i]->pitch_x = tile_light->width + 1;
        field_draw_context[i]->pitch_y = tile_light->height + 1;
    }
    printf("Lookup table created\n");
}