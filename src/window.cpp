#include "../include/Window.hpp"

Window::Window(int width, int height, std::string windowName) {
    // Check if glfw init failed
    if (!glfwInit()) {
        std::cout << "Error initializing GLFW" << std::endl;
    }

    // Window Hints
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Set current window and check if for errors
    Window::currentWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

    if (!Window::currentWindow) {
        std::cout << "Error creating window" << std::endl;
        glfwTerminate();
    }
}

void Window::changeScene(int newScene) {
    switch (newScene) {
        case 0:
            Window::currentScene = new EditorScene();
            Window::currentScene->init();
            Window::currentSceneIndex = newScene;
            break;
        case 1:
            Window::currentScene = new GameScene();
            Window::currentScene->init();
            Window::currentSceneIndex = newScene;
            break;
        default:
            std::cout << "ERROR: Unknown scene " << newScene << std::endl;
            exit(EXIT_FAILURE);
    }
}

void Window::run() {
    // Set mouse Listener
    MouseListener mouseListener(currentWindow);
    
    // Set callbacks
    glfwSetKeyCallback(currentWindow, KeyboardListener::KeyCallback);
    glfwSetCursorPosCallback(currentWindow, MouseListener::MouseCursorCallback);
    glfwSetScrollCallback(currentWindow, MouseListener::MouseScrollCallback);
    glfwSetMouseButtonCallback(currentWindow, MouseListener::MouseButtonCallback);

    // Make window context
    glfwMakeContextCurrent(Window::currentWindow);

    // Creating glew context
    GLenum err;
    if ((err = glewInit()) != GLEW_OK) {
        std::cout << "ERROR: glew init failed -> " << glewGetErrorString(err) << std::endl;
    }

    // Create imgui context
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup imgui style
    ImGui::StyleColorsDark();

    // Setup platform render backends
    ImGui_ImplGlfw_InitForOpenGL(Window::currentWindow, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Enable V-SYNC
    glfwSwapInterval(1);

    // Make window visible
    glfwShowWindow(Window::currentWindow);

    // Hello Worlds :)
    std::cout << "Hello GLFW -> " << glfwGetVersionString() << std::endl;
    std::cout << "Hello GLEW -> " << glGetString(GL_VERSION) << std::endl; 

    // Seed random function
    srand(static_cast<unsigned> (time(0)));

    Window::changeScene(0);
}

void Window::loop() {
    while (!glfwWindowShouldClose(Window::currentWindow)) {
        glfwPollEvents();

        // Exit event 
        if (KeyboardListener::GetKeyDown(GLFW_KEY_ESCAPE)) {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        Window::currentScene->update();
        

        MouseListener::endFrame();

        glfwSwapBuffers(Window::currentWindow);

        Time::endTime = Time::GetMilliseconds();
        Time::dt = Time::endTime - Time::beginTime;
        Time::beginTime = Time::endTime;
    }

    EditorScene::freeResources();
    GameScene::freeResources();
}

void Window::clearEverything() {
    delete Window::currentScene;
    // Destroy ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Destroy glfw
    glfwDestroyWindow(Window::currentWindow);
    glfwTerminate(); 
}

GLFWwindow* Window::getWindow() {
    return Window::currentWindow;
}

int Window::getSceneIndex() {
    return Window::currentSceneIndex;
}

Scene* Window::currentScene;
int Window::currentSceneIndex;

GLFWwindow* Window::currentWindow = NULL;
