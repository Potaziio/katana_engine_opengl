#include "../include/Window.hpp"

Shader defaultShader("../assets/Shaders/default.glsl");

void Window::error_callback(int error, const char* description) {
    fprintf(stderr, "ERROR: %s\n", description);
}

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
    currentWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

    if (!currentWindow) {
        std::cout << "Error creating window" << std::endl;
        glfwTerminate();
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
    glfwSetErrorCallback(Window::error_callback);

    // Make window context
    glfwMakeContextCurrent(currentWindow);

    // Creating glew context

    GLenum err;
    if ((err = glewInit()) != GLEW_OK) {
        std::cout << "ERROR: glew init failed -> " << glewGetErrorString(err) << std::endl;
    }

    // Enable V-SYNC
    glfwSwapInterval(1);

    // Make window visible
    glfwShowWindow(currentWindow);

    // Hello Worlds

    std::cout << "Hello GLFW -> " << glfwGetVersionString() << std::endl;
    printf("Hello GLEW -> (%s)", glGetString(GL_VERSION));
    printf("\n");

    defaultShader.compileShaders();

    // Drawing the first triangle
     float vertices[] = {
         -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f, 0.5f, 0.0f 
     };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Window::loop() {
    while (!glfwWindowShouldClose(currentWindow)) {
        // Clear the color 
        glClearColor(131.0f / 255.0f, 201.0f / 255.0f, 239.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
   
        defaultShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers
        glfwSwapBuffers(currentWindow);

        // Poll for events here
        glfwPollEvents();

        if (KeyboardListener::isKeyPressed(GLFW_KEY_ESCAPE)) {
            std::cout << "\n Exiting..." << std::endl;
            break;
        }

        /* std::cout << "FPS: " << (0.001 / ((float)Time::DeltaTime() / 1000.0f)) << std::endl; */

        MouseListener::endFrame();
    }
}

void Window::clearGLFW() {
    glfwDestroyWindow(currentWindow);
    glfwTerminate(); 
}
