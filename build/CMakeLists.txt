cmake_minimum_required(VERSION 3.0.0)
project(Katana_Engine VERSION 0.0.1)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file (GLOB KATANA_SOURCE_FILES
    "../src/*.cpp"
    )

file (GLOB IMGUI_SOURCES
    "../include/imgui/*.cpp"
    )

file (GLOB INCLUDE_DIRS 
    "../include/imgui/*.h"
    "../include/*.hpp"
    "../include/math/*.hpp"
    "../include/util*.hpp"
    )

include_directories(Katana_Engine ${KATANA_INCLUDE_FILES})

add_library(imgui_lib STATIC ${IMGUI_SOURCES})

add_executable(Katana_Engine ${KATANA_SOURCE_FILES})

target_link_libraries(Katana_Engine PUBLIC GL GLEW glfw ${CMAKE_DL_LIBS})

