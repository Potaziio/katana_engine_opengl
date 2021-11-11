#include "../include/scene/GameScene.hpp"

float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;

bool changeScene = false;
bool hasFinishedAnimation = false;

Shader game_defaultShader = Shader("../assets/Shaders/default.glsl");

unsigned int game_VAO, game_VBO, game_EBO;

Texture game_myTexture;

glm::vec3 game_cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
glm::vec3 game_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 game_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float game_cameraSpeed = 10;

void GameScene::init() {
    std::cout << "In Game scene" << std::endl;
    game_myTexture = Texture("../assets/Textures/container.jpg");

    this->p_camera = Camera(glm::vec3(0.0f, 0.0f, 6.0f), 0.1f, 100.0f, 45.0f);

    if (changeScene) {
        changeScene = false;
        hasFinishedAnimation = false;
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
    }

    game_defaultShader.compileShaders();

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
    glGenVertexArrays(1, &game_VAO);
    glGenBuffers(1, &game_VBO);
    glGenBuffers(1, &game_EBO);
    glBindVertexArray(game_VAO);

    // VBO set up
    glBindBuffer(GL_ARRAY_BUFFER, game_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // EBO set up
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, game_EBO);
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
}

void GameScene::update() {
    if (r >= 0.0f) {
        r -= Time::DeltaTime();
        g -= Time::DeltaTime();
        b -= Time::DeltaTime();
    }
    else {
        hasFinishedAnimation = true;
    }

    this->p_camera.updateViewMatrix();
    
    if (hasFinishedAnimation && !changeScene && KeyboardListener::GetKeyDown(GLFW_KEY_SPACE)) {
        Window::changeScene(0);
        changeScene = true;
    }

    if (KeyboardListener::GetKeyDown(GLFW_KEY_W)) {
        this->p_camera.cameraPos += (game_cameraSpeed * game_cameraUp) * Time::DeltaTime();
    }

    if (KeyboardListener::GetKeyDown(GLFW_KEY_S)) {
        this->p_camera.cameraPos -= (game_cameraSpeed * game_cameraUp) * Time::DeltaTime();
    }

    if (KeyboardListener::GetKeyDown(GLFW_KEY_D)) { 
        this->p_camera.cameraPos += (glm::normalize(glm::cross(game_cameraFront, game_cameraUp)) * game_cameraSpeed) * Time::DeltaTime();
    }

    if (KeyboardListener::GetKeyDown(GLFW_KEY_A)) {
        this->p_camera.cameraPos -= (glm::normalize(glm::cross(game_cameraFront, game_cameraUp)) * game_cameraSpeed) * Time::DeltaTime();
    }


    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);

    game_defaultShader.use();
    game_defaultShader.sendTexture("texture1", game_myTexture, 0);

    glActiveTexture(GL_TEXTURE0);
    game_myTexture.bind();

    game_defaultShader.sendMat4("model", this->p_camera.getTransfomMatrix());
    game_defaultShader.sendMat4("projection", this->p_camera.getProjectionMatrix());
    game_defaultShader.sendMat4("view", this->p_camera.getViewMatrix());

    glBindVertexArray(game_VAO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    glBindVertexArray(0);

    game_defaultShader.detach();
}

void GameScene::freeResources() {
    std::cout << "Freeing resources from game scene" << std::endl;
    glDeleteVertexArrays(1, &game_VAO);
    glDeleteBuffers(1, &game_VBO);
    glDeleteBuffers(1, &game_EBO);
}
