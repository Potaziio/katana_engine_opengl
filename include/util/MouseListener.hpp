#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "../math/Vector.hpp"

class MouseListener {
    private:
        static double xPos, yPos;

        static Vector2d mousePos;
        static Vector2d lastMousePos;
        static Vector2d scroll;
        static bool mouseButtonPressed[4];
        static bool isDragging;
        static GLFWwindow* window;

        static bool firstMove;
    public:
        MouseListener(GLFWwindow* p_window);

        static void MouseCursorCallback(GLFWwindow* window, double xpos, double ypos);
        static void MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void endFrame();

        static Vector2d GetMousePos();
        static Vector2d GetMouseScroll();
        static Vector2d GetLastMousePos();

        static bool isMouseDragging();
        static bool mouseButtonDown(int button);
};
