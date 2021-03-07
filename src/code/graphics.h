#ifndef graphics
#define graphics

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

typedef struct Sprites
{
    SDL_Surface *sprite_surface;

} Sprite;

int initialize_graphics(char *app_name, int screen_width, int screen_height);

void clear_screen();

void update_screen();

void shut_down_graphics();

Sprite *create_sprite(char *path);
void destroy_sprite(Sprite *sprite);

#endif