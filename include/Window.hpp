#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include "Shader.hpp"
#include "util/KeyboardListener.hpp"
#include "util/Time.hpp"
#include "util/MouseListener.hpp"
#include "scene/EditorScene.hpp"
#include "scene/GameScene.hpp"
#include "scene/Scene.hpp"
#include "math/MathUtils.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <iostream>
#include <string>

class Window {
    private:
        static GLFWwindow* currentWindow;
        int win_width;
        int win_height;
        std::string win_name;

        static int currentSceneIndex;
        static Scene* currentScene;
    public:
        Window(int width, int height, std::string windowName);

        static GLFWwindow* getWindow();
        void run();
        void loop();
        static void changeScene(int newScene);
        static int getSceneIndex();
        void clearEverything();
};
