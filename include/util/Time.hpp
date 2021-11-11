#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Time {
    public:
        static float dt;
        static float beginTime;
        static float endTime;

        static float GetMilliseconds();
        static float DeltaTime();
};
