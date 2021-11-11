#pragma once

#include "Camera.hpp"

class Scene {
    public:
        Camera p_camera;
        virtual void init() {}
        virtual void update() {}
        static void freeResources() {}
};
