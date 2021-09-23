#include "../include/Input.hpp"

bool Input::GetKeyDown(SDL_Event event, SDL_KeyCode key)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (!event.key.repeat)
        {
            if (event.key.keysym.sym == key)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }

    return false;
}

// Keys

SDL_KeyCode Input::Space = SDLK_SPACE;
SDL_KeyCode Input::E = SDLK_e;
SDL_KeyCode Input::A = SDLK_a;
SDL_KeyCode Input::D = SDLK_d;
SDL_KeyCode Input::W = SDLK_w;
SDL_KeyCode Input::F = SDLK_f;
SDL_KeyCode Input::G = SDLK_g;
SDL_KeyCode Input::ESCAPE = SDLK_ESCAPE;
