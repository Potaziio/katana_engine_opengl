#pragma once

#include <iostream>
#include "../stb_image/stb_image.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

class Texture {
    private: 
        int width, height, nrChannels;
        unsigned char* data;
        unsigned int textureID;
        const char* filepath;
    public:
        Texture(const char* filepath);
        Texture();

        unsigned char* getData();
        unsigned int getTextureID();

        void bind();
        void unbind();

        int getWidth();
        int getHeight();
        void freeImageMem();
        bool isGood();
};
