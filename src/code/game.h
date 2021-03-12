#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "blocks.h"
#include "game_time.h"

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 22

typedef struct Game
{
    int msec_between_block_moves;
    Field *game_field;
    Field *current_block_field;
    BlockInstance *current_block;

} Game;

Game *initialize_game();

void update_game(Game *game);

void draw_game(Game *game);

FieldDrawContext *field_draw_context;
void initialize_draw_context();

#endif