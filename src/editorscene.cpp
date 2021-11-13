#include "../include/scene/EditorScene.hpp"

ImVec4 clear_color = ImVec4(131.0f / 255.0f, 201.0f / 255.0f, 239.0f / 255.0f, 1.0f);
Shader defaultShader("../assets/Shaders/default.glsl");
bool changingScene = false;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float cameraSpeed = 10;

GameObject player = GameObject("Player");

void EditorScene::init() {
    this->camera = Camera(glm::vec3(0.0f, 0.0f, 6.0f), 0.1f, 100.0f, 45.0f);

    player.addComponent(new Transform(glm::vec3(0.0f, 0.0f, 0.5f)));
    player.addComponent(new MeshRenderer(2.0f, 2.0f, glm::vec3(0.0f, 0.0f, 1.0f), true));

    this->addObjectToScene(player);

    std::cout << "In editor scene" << std::endl;

    // Compile shaders
    defaultShader.compileShaders();

    /* glfwSetInputMode(Window::getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN | GLFW_CURSOR_DISABLED); */
}

void EditorScene::update() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        // Start imgui new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Hello ImGui!!");
            ImGui::SetWindowFontScale(1.2);
            ImGui::ColorEdit3("Window color", (float*)&clear_color);
            ImGui::Text("FPS: %.1f", (0.001f / ((float)Time::DeltaTime() / 1000.0f)));

            if (ImGui::Button("Render cube")) {
                if (player.getComponent<MeshRenderer>()->isEnabled == false) {
                    player.getComponent<MeshRenderer>()->isEnabled = true;
                } else {
                    player.getComponent<MeshRenderer>()->isEnabled = false;
                }
            }

            ImGui::End();
        }

        if (!changingScene && KeyboardListener::GetKeyDown(GLFW_KEY_ENTER)) {
            Window::changeScene(1);
            changingScene = true;
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_W)) {
            this->camera.cameraPos += (cameraSpeed * cameraUp) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_S)) {
            this->camera.cameraPos -= (cameraSpeed * cameraUp) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_D)) { 
            this->camera.cameraPos += (glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_A)) {
            this->camera.cameraPos -= (glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_P) && !changingScene) {
            changingScene = true;
            Window::changeScene(1);
        }

        this->camera.cameraPos.z -= (MouseListener::GetMouseScroll().y * 15) * Time::DeltaTime();

        this->camera.updateViewMatrix();

        // Render here

        // Render Imgui
        ImGui::Render();

        // Clear the color 
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        defaultShader.use();

        defaultShader.sendMat4("model", player.getComponent<Transform>()->modelMatrix);
        defaultShader.sendMat4("projection", this->camera.getProjectionMatrix());
        defaultShader.sendMat4("view", this->camera.getViewMatrix());

        player.getComponent<MeshRenderer>()->render();

        defaultShader.detach();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        MouseListener::endFrame();
}

void EditorScene::freeResources() {
    std::cout << "Freeing resources from editor scene" << std::endl;
    player.getComponent<MeshRenderer>()->freeResources();
}
