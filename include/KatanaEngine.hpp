#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <GLFW/glfw3.h>

#include "RenderWindow.hpp"
#include "Input.hpp"
#include "Shape.hpp"
#include "LoadShaders.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"

#define Log(x) std::cout << x << std::endl;

