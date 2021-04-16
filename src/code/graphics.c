#include "graphics.h"
#include "stdio.h"

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;

int initialize_graphics(char *app_name, int screen_width, int screen_height)
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    //Create window
    window = SDL_CreateWindow(app_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -2;
    }
    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Could not initialize renderer. SDL_Error: %s\n", SDL_GetError());
        return -3;
    }
    int image_flags = IMG_INIT_PNG;
    if (!(IMG_Init(image_flags) & image_flags))
    {
        printf("Could not initialize SDL2_image\n");
        return -4;
    }
    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("Could not initialize SDL_TTF SDL_ttf Error: %s\n", TTF_GetError());
        return -5;
    }

    // Load up font

    //Globally used font

    font = TTF_OpenFont("assets/minecrafter.ttf", 50);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return -6;
    }

    return 0;
}

void clear_screen()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void update_screen()
{
    SDL_RenderPresent(renderer);
}

void shut_down_graphics()
{
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}

Sprite *create_sprite(char *path)
{
    SDL_Surface *loaded_surface = IMG_Load(path);

    if (loaded_surface == NULL)
    {
        printf("Could not load texture in %s", path);
        return NULL;
    }
    SDL_Texture *new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if (new_texture == NULL)
    {
        printf("Could not create texture from surface");
        return NULL;
    }
    Sprite *output_sprite = malloc(sizeof(Sprite));
    output_sprite->sprite_texture = new_texture;
    output_sprite->width = loaded_surface->w;
    output_sprite->height = loaded_surface->h;

    return output_sprite;
}

void draw_sprite(Sprite *sprite, int x, int y)
{
    SDL_Rect target_rect;
    target_rect.x = x;
    target_rect.y = y;
    target_rect.w = sprite->width;
    target_rect.h = sprite->height;
    SDL_RenderCopy(renderer, sprite->sprite_texture, NULL, &target_rect);
}

void destroy_sprite(Sprite *sprite)
{
    free(sprite);
    return;
}

void draw_text(char *text, int x, int y, Color text_color)
{
    SDL_Color tc = {text_color.red, text_color.green, text_color.blue};

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, tc);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect target_rect;

    target_rect.w = textSurface->w;
    target_rect.h = textSurface->h;
    target_rect.x = x - target_rect.w / 2;
    target_rect.y = y - target_rect.h / 2;
    SDL_RenderCopy(renderer, text_texture, NULL, &target_rect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text_texture);
}