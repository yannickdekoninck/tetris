#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>

#include "field.h"
#include "blocks.h"
#include "game_time.h"

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 22

#define MAX_BLOCKS 10000

typedef struct Game
{
    int msec_between_block_moves;
    Field *game_field;
    Field *current_block_field;
    BlockInstance *current_block;
    int *block_sequence;
    int sequence_id;

} Game;

Game *initialize_game();

void update_game(Game *game);

void draw_game(Game *game);

bool move_current_block(Game *game, int dx, int dy);

void rotate_current_block(Game *game);

void drop_current_block(Game *game);

FieldDrawContext *field_draw_context;
void initialize_draw_context();

void next_block(Game *game);

void block_down(Game *game);

void check_lines(Game *game);

#endif