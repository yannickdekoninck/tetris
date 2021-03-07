#include "graphics.h"
#include <SDL.h>
#include "stdio.h"

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;

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
    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    return 0;
}

void clear_screen()
{
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
}

void draw()
{
    SDL_UpdateWindowSurface(window);
}

void shut_down_graphics()
{
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}