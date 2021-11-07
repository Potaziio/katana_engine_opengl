#include "../include/util/KeyboardListener.hpp"

void KeyboardListener::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        keyPressed[key] = false;
    }
}

bool KeyboardListener::isKeyPressed(int keyCode) {
    return keyPressed[keyCode];
}

bool KeyboardListener::keyPressed[350];
