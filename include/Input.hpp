#pragma once
#include <SDL2/SDL.h>

struct Input
{
    static bool GetKeyDown(SDL_Event event, SDL_KeyCode key);

    static SDL_KeyCode Space;
    static SDL_KeyCode E;
    static SDL_KeyCode A;
    static SDL_KeyCode D;
    static SDL_KeyCode S;
    static SDL_KeyCode W;
    static SDL_KeyCode F;
    static SDL_KeyCode G;
    static SDL_KeyCode ESCAPE;
};
