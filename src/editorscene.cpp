#include "../include/scene/EditorScene.hpp"

ImVec4 clear_color = ImVec4(131.0f / 255.0f, 201.0f / 255.0f, 239.0f / 255.0f, 1.0f);
Shader defaultShader("../assets/Shaders/default.glsl");
unsigned int VAO, VBO, EBO;
bool changingScene = false;

Texture myTexture; 

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float cameraSpeed = 10;

float valTest = 10;

void EditorScene::init() {
    myTexture = Texture("../assets/Textures/awesomeface.png");

    this->p_camera = Camera(glm::vec3(0.0f, 0.0f, 6.0f), 0.1f, 100.0f, 45.0f);

    std::cout << "In editor scene" << std::endl;

    // Compile shaders
    defaultShader.compileShaders();

    float vertices[] = {
        0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,     1.0f, 1.0f,   // Top Right
        0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,     1.0f, 0.0f,   // Bottom Right 
       -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,     0.0f, 0.0f,   // Bottom Left
       -0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,     0.0f, 1.0f    // Top Left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    // Generate VBO and EBO buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    // VBO set up
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // EBO set up
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

     // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Unbind VAO
    glBindVertexArray(0);

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
            ImGui::ColorEdit3("Window color", (float*)&clear_color);
            ImGui::Text("FPS: %.1f", (0.001f / ((float)Time::DeltaTime() / 1000.0f)));
            ImGui::End();
        }

        if (!changingScene && KeyboardListener::GetKeyDown(GLFW_KEY_ENTER)) {
            Window::changeScene(1);
            changingScene = true;
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_W)) {
            this->p_camera.cameraPos += (cameraSpeed * cameraUp) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_S)) {
            this->p_camera.cameraPos -= (cameraSpeed * cameraUp) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_D)) { 
            this->p_camera.cameraPos += (glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_A)) {
            this->p_camera.cameraPos -= (glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed) * Time::DeltaTime();
        }

        if (KeyboardListener::GetKeyDown(GLFW_KEY_P) && !changingScene) {
            changingScene = true;
            Window::changeScene(1);
        }

        this->p_camera.updateViewMatrix();

        // Render here

        // Render Imgui
        ImGui::Render();

        // Clear the color 
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
       
        defaultShader.use();
        defaultShader.sendTexture("texture1", myTexture, 0);
        glActiveTexture(GL_TEXTURE0);
        myTexture.bind();

        defaultShader.sendMat4("model", this->p_camera.getTransfomMatrix());
        defaultShader.sendMat4("projection", this->p_camera.getProjectionMatrix());
        defaultShader.sendMat4("view", this->p_camera.getViewMatrix());

        glBindVertexArray(VAO);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        glBindVertexArray(0);

        defaultShader.detach();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        MouseListener::endFrame();
}

void EditorScene::freeResources() {
    std::cout << "Freeing resources from editor scene" << std::endl;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
