#include "../include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char* win_name, int width, int height, Uint32 win_flags)
: window(NULL)
{
    RenderWindow::win_width = width;
    RenderWindow::win_height = height;

    window = SDL_CreateWindow(win_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, win_flags);

    if (window == NULL)
    {
        std::cout << "Window failed to init, Error" << SDL_GetError() << std::endl;
    }

    assert(window);
}


void RenderWindow::CleanUp(SDL_Window* win)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(RenderWindow::context);
    SDL_DestroyWindow(win);
    SDL_Quit();
}


void RenderWindow::UpdateGl(SDL_Window* win, float r, float g, float b, float a)
{
    glViewport(0, 0, RenderWindow::win_width, RenderWindow::win_height);
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void RenderWindow::SwapWindow(SDL_Window* win)
{
    SDL_GL_SwapWindow(win);
}

SDL_GLContext RenderWindow::GLContext(SDL_Window* win)
{
    SDL_GLContext Context = SDL_GL_CreateContext(win);
    RenderWindow::context = Context;
    return Context;  
}

SDL_GLContext RenderWindow::context = NULL;

int RenderWindow::win_width = 0;
int RenderWindow::win_height = 0;
