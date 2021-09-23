#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

class LoadShaders
{
    public:
        static GLuint shader;
        LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
};
