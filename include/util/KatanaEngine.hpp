#pragma once

#include <iostream>
#include <stdio.h>
#include <assert.h>

#include "../Shader.hpp"

#include <GLFW/glfw3.h>

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../Scene.hpp"
#include "KeyboardListener.hpp"
#include "MouseListener.hpp"
#include "Time.hpp"

#define Log(x) std::cout << x << std::endl;
#define ErrLog(x) std::cout << "ERROR: " << x << std::endl;
