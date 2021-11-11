#pragma once

#include "Scene.hpp"
#include "../Shader.hpp"
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../util/KeyboardListener.hpp"
#include "../util/MouseListener.hpp"
#include "../util/Time.hpp"
#include "../Window.hpp"
#include "../util/Texture.hpp"

class EditorScene : public Scene {
    public:
        void update() override;
        void init() override;
        static void freeResources();
};
