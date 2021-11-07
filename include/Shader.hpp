#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>

class Shader {
    private:
        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        const char* vertexShaderSource;
        const char* fragmentShaderSource;

        std::vector<std::string> holder;

        std::string ShaderPath;
    public:
        Shader(std::string shaderPath);

        void use();
        void compileShaders();
        void detach();
};
