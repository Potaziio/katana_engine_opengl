#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

class KeyboardListener {
    private: 
        static bool keyPressed[350];
    public:
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static bool isKeyPressed(int keyCode);
};
