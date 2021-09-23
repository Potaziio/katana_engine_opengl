#pragma once
#include <iostream>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>
#include "Shape.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

class RenderWindow
{
    public:
        SDL_Window* window;
        static SDL_GLContext context;

        static int win_width;
        static int win_height;

        RenderWindow(const char* win_name, int width, int height, Uint32 win_flags);
        
        static void CleanUp(SDL_Window* win);
        static void UpdateGl(SDL_Window* win, float r, float g, float b, float a);
        static void SwapWindow(SDL_Window* win);
        static SDL_GLContext GLContext(SDL_Window* win);
};



class DrawShape
{
    public:
       DrawShape(); 
};
