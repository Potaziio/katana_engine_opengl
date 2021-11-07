#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Time {
    private:
        static float dt;
        static float beginTime;
        static float endTime;
    public:
        static float GetMilliseconds();
        static float DeltaTime();
};
