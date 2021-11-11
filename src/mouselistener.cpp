#include "../include/util/MouseListener.hpp"

// Constructor

MouseListener::MouseListener(GLFWwindow* p_window) {
    MouseListener::mousePos = Vector2d(0.0f, 0.0f);
    MouseListener::lastMousePos = Vector2d(0.0f, 0.0f);
    MouseListener::scroll = Vector2d(0.0f, 0.0f);

    MouseListener::window = p_window; 
}

// Mouse cursor movement callback

void MouseListener::MouseCursorCallback(GLFWwindow* window, double xpos, double ypos) {
    if (MouseListener::firstMove) 
    {
        MouseListener::lastMousePos = Vector2d(xpos, ypos);
        MouseListener::firstMove = false; 
    }
    else 
        MouseListener::lastMousePos = Vector2d(MouseListener::mousePos.x, MouseListener::mousePos.y);

    MouseListener::mousePos = Vector2d(xpos, ypos);
}

// Mouse scroll callback

void MouseListener::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    MouseListener::scroll = Vector2d(xOffset, yOffset);
}

// Mouse button press Callback

void MouseListener::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (button < (int)sizeof MouseListener::mouseButtonPressed / (int)sizeof MouseListener::mouseButtonPressed[0]) {
            MouseListener::mouseButtonPressed[button] = true;
        }
    }
    else if (action == GLFW_RELEASE) {
        MouseListener::mouseButtonPressed[button] = false;
        MouseListener::isDragging = false;
    }
}

// Resets Things at the end of frame 

void MouseListener::endFrame() {
    MouseListener::lastMousePos = Vector2d(MouseListener::mousePos.x, MouseListener::mousePos.y);
    MouseListener::scroll = Vector2d(0.0f, 0.0f);
    MouseListener::isDragging = MouseListener::mouseButtonPressed[0] || MouseListener::mouseButtonPressed[1] || MouseListener::mouseButtonPressed[2];
}

// To get the mouse position

Vector2d MouseListener::GetMousePos() {
    glfwGetCursorPos(MouseListener::window, &MouseListener::xPos, &MouseListener::yPos);
    return Vector2d(MouseListener::xPos, MouseListener::yPos);
}

Vector2d MouseListener::GetLastMousePos() {
    return lastMousePos;
}

// To get the mouse scroll

Vector2d MouseListener::GetMouseScroll() {
    return MouseListener::scroll;
}

// To get the dragging state

bool MouseListener::isMouseDragging() {
    return MouseListener::isDragging;
}

// To get the button state 

bool MouseListener::mouseButtonDown(int button) {
    if (button < (int)sizeof MouseListener::mouseButtonPressed / (int)sizeof MouseListener::mouseButtonPressed[0]) {
        return MouseListener::mouseButtonPressed[button];
    } else {
        return false;
    }
}

GLFWwindow* MouseListener::window;

double MouseListener::xPos, MouseListener::yPos;

Vector2d MouseListener::mousePos;
Vector2d MouseListener::lastMousePos;
Vector2d MouseListener::scroll;

bool MouseListener::mouseButtonPressed[4];
bool MouseListener::isDragging;

// Check if its the first movement of the mouse, this is to prevent mouse jump when first focusing the window
bool MouseListener::firstMove = true;
