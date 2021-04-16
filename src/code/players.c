#include "players.h"
#include "stdlib.h"

void init_players()
{
    number_of_players = 3;
    players = malloc(sizeof(char *) * number_of_players);

    players[0] = "Lynn";
    players[1] = "Yannick";
    players[2] = "Guest";
}