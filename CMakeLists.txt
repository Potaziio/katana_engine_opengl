cmake_minimum_required(VERSION 3.0.0)
project(Katana_Engine VERSION 0.0.1)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

find_package(SDL2 REQUIRED)
find_package(imgui REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(Katana_Engine ${KATANA_INCLUDE_FILES} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file (GLOB KATANA_SOURCE_FILES
    "src/*.cpp"
    )

file (GLOB IMGUI_SOURCES
    "include/imgui/*.cpp"
    )

add_library(imgui STATIC ${IMGUI_SOURCES})

add_executable(Katana_Engine ${KATANA_SOURCE_FILES})

target_link_libraries(Katana_Engine PUBLIC imgui SDL2main SDL2_image SDL2 GL glfw ${CMAKE_DL_LIBS})
