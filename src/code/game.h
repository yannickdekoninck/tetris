#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>

#include "field.h"
#include "blocks.h"
#include "game_time.h"
#include "stdbool.h"

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 22

#define MAX_BLOCKS 10000

#define STATE_STARTING 0
#define STATE_RUNNING 1
#define STATE_FINISHED 2

int gamestate;

typedef struct Game
{
    int msec_between_block_moves;
    Field *game_field;
    Field *current_block_field;
    BlockInstance *current_block;
    int *block_sequence;
    int sequence_id;
    int total_lines;
    int input_channel;
    int player_id;
    bool ready;
    bool winner;

} Game;

Game *initialize_game(int input_channel);

void update_game(Game *game);

void draw_game(Game *game, int draw_x);

bool move_current_block(Game *game, int dx, int dy);

void rotate_current_block(Game *game);

void drop_current_block(Game *game);

FieldDrawContext **field_draw_context;
void initialize_draw_context();

void next_block(Game *game);

void block_down(Game *game);

void check_lines(Game *game);

int number_of_games;

#endif