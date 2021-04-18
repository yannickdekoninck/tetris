#ifndef graphics
#define graphics

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>

#define COLOR_BLUE                          \
    {                                       \
        .red = 40, .green = 73, .blue = 107 \
    }

#define COLOR_GREEN  \
    {                \
        104, 152, 90 \
    }

typedef struct Sprites
{
    SDL_Texture *sprite_texture;
    int width;
    int height;

} Sprite;

typedef struct Color
{
    int red;
    int green;
    int blue;
} Color;

int initialize_graphics(char *app_name, int screen_width, int screen_height);

void clear_screen();

void update_screen();

void shut_down_graphics();

Sprite *create_sprite(char *path);
void destroy_sprite(Sprite *sprite);
void draw_sprite(Sprite *sprite, int x, int y);

void draw_text(char *text, int x, int y, Color text_color);

#endif