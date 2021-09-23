#include "../include/KatanaEngine.hpp"

int main(int argc, char* args[])
{
    uint32_t WindowFlags = SDL_WINDOW_OPENGL;
    RenderWindow window("Katana Engine", 1800, 1000, WindowFlags);
    SDL_Window* win = window.window;
    SDL_GLContext Context = RenderWindow::GLContext(win);
    
    Shape::SetTriangleVertices();

    int32_t Running = 1;
    int32_t Fullscreen = 0;

    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(win, Context);

    ImGui_ImplOpenGL3_Init("#version 130");

    float w_r = 0.0f;
    float w_g = 0.0f;
    float w_b = 0.0f;
    float w_a = 0.0f;

    float t_r = 1.0f;
    float t_g = 0.0f;
    float t_b = 0.0f;
    
    LoadShaders triangle_shader = LoadShaders("assets/Shaders/SimpleVertexShader.shader", "assets/Shaders/SimpleFragmentShader.fshader");

    while (Running)
    {
        ImGuiIO& io = ImGui::GetIO();

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);

            if (Input::GetKeyDown(event, Input::ESCAPE))
            {
                Running = 0;
            }

            if (Input::GetKeyDown(event, Input::F))
            {
                Fullscreen = !Fullscreen;

                if (Fullscreen)
                    SDL_SetWindowFullscreen(win, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
                else
                    SDL_SetWindowFullscreen(win, WindowFlags);
            }

            if (event.type == SDL_QUIT)
            {
                Running = 0;
            }

            if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    io.DisplaySize.x = static_cast<float>(event.window.data1);
                    io.DisplaySize.y = static_cast<float>(event.window.data2);
                }
            }
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::Begin("Hello Window");
            ImGui::Text("Demo Window");
            ImGui::Spacing();
            ImGui::SliderFloat("R: ", &w_r, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::SliderFloat("G: ", &w_g, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::SliderFloat("B: ", &w_b, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::SliderFloat("A: ", &w_a, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::SliderFloat("Triangle R: ", &t_r, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::SliderFloat("Triangle G: ", &t_g, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::SliderFloat("Triangle B: ", &t_b, 0.0f, 1.0f);
 
            for (int i = 0; i < 5; i++)
            {
                ImGui::Spacing();
            }

            ImGui::End();
        }
        
        ImGui::Render();

        RenderWindow::UpdateGl(win, w_r, w_g, w_b, w_a);

        Shape::DisplayTriangle(triangle_shader, t_r, t_g, t_b);

        RenderWindow::SwapWindow(win);
    }

    // ----------------------------------------------------------------------------------------------------------------------------------------------
    
    RenderWindow::CleanUp(win);

    return 0;
}
