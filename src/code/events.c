#include "SDL2/SDL.h"
#include "events.h"

void initialize_gamepads()
{
    int number_of_joysticks = SDL_NumJoysticks();
    printf("Number of joysticks: %d\n", number_of_joysticks);
    if (number_of_joysticks > 0)
    {
        gamepads = malloc(sizeof(SDL_Joystick *) * number_of_joysticks);
        for (int i = 0; i < number_of_joysticks; i++)
        {
            gamepads[i] = SDL_JoystickOpen(i);
        }
    }
}

void initialize_events()
{
    keyboard_event_counter = 0;
    keyboard_events = malloc(sizeof(int) * EVENTBUFFERSIZE);
    initialize_gamepads();
}

bool get_events()
{
    SDL_Event e;
    bool quit;
    keyboard_event_counter = 0;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }

        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                keyboard_events[keyboard_event_counter].key = KEYUP;
                break;
            case SDLK_DOWN:
                keyboard_events[keyboard_event_counter].key = KEYDOWN;
                break;
            case SDLK_LEFT:
                keyboard_events[keyboard_event_counter].key = KEYLEFT;
                break;
            case SDLK_RIGHT:
                keyboard_events[keyboard_event_counter].key = KEYRIGHT;
                break;
            case SDLK_SPACE:
                keyboard_events[keyboard_event_counter].key = KEYSPACE;
                break;

            default:
                keyboard_event_counter--;
            }
            keyboard_event_counter++;
        }
        if (e.type == SDL_JOYBUTTONDOWN)
        {
            int button_id = e.jbutton.button;
            printf("Button pushed: %d\n", button_id);
        }
        if (e.type == SDL_JOYAXISMOTION)
        {
            // Axis 0 = x
            // Axis 1 = y
            int threshold = 32000;
            int joystick_axis = e.jaxis.axis;
            int axis_value = e.jaxis.value;

            if (joystick_axis == 0)
            {
                if (axis_value < -threshold)
                {
                    keyboard_events[keyboard_event_counter].key = KEYLEFT;
                    keyboard_event_counter++;
                }
                if (axis_value > threshold)
                {
                    keyboard_events[keyboard_event_counter].key = KEYRIGHT;
                    keyboard_event_counter++;
                }
            }
            if (joystick_axis == 1)
            {
                if (axis_value < -threshold)
                {
                    keyboard_events[keyboard_event_counter].key = KEYUP;
                    keyboard_event_counter++;
                }
                if (axis_value > threshold)
                {
                    keyboard_events[keyboard_event_counter].key = KEYDOWN;
                    keyboard_event_counter++;
                }
            }
        }
    }
    return quit;
}