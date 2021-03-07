#include "graphics.h"
#include "stdio.h"

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
SDL_Renderer *renderer = NULL;

int initialize_graphics(char *app_name, int screen_width, int screen_height)
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
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
    Sprite *output_sprite = malloc(sizeof(Sprite));
    output_sprite->sprite_surface = IMG_Load(path);
    return output_sprite;
}

void destroy_sprite(Sprite *sprite)
{
    free(sprite);
    return;
}