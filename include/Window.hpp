#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include "Shader.hpp"
#include "util/KeyboardListener.hpp"
#include "util/Time.hpp"
#include "util/MouseListener.hpp"

#include <iostream>
#include <string>

class Window {
    private:
        GLFWwindow* currentWindow;
        int win_width;
        int win_height;
        std::string win_name;

        unsigned int shaderProgram;
        unsigned int VAO;
    public:
        Window(int width, int height, std::string windowName);

        static void error_callback(int error, const char* description);
        void run();
        void loop();
        void clearGLFW();
};
