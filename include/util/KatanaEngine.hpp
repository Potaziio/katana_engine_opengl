#pragma once

#include <iostream>
#include <stdio.h>
#include <assert.h>

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.cpp"

#define Log(x) std::cout << x << std::endl;
#define ErrLog(x) std::cout << "ERROR: " << x << std::endl;
