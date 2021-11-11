#include "../include/util/KeyboardListener.hpp"

void KeyboardListener::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        KeyDown[key] = true;
    } else if (action == GLFW_RELEASE) {
        KeyDown[key] = false;
    }
}

bool KeyboardListener::GetKeyDown(int keyCode) {return KeyDown[keyCode];}

bool KeyboardListener::KeyDown[350];
