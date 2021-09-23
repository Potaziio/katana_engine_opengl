#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GLES3/gl3.h>

#include "LoadShaders.hpp"

struct Shape
{
    static const GLfloat Triangle[];

    static GLuint VertexBuffer;

    // Setting up vertices
    
    static void SetTriangleVertices();
    static void DisplayTriangle(LoadShaders TriangleShader, float r, float g, float b);
};
