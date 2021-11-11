#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "util/Texture.hpp"

class Shader {
    private:
        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        const char* vertexShaderSource;
        const char* fragmentShaderSource;

        bool beingUsed;

        std::vector<std::string> holder;

        std::string ShaderPath;
    public:
        Shader(std::string shaderPath);

        void use();
        void compileShaders();
        void detach();

        // Send variables to shader

        void sendTexture(const char* varName, Texture texture, GLint position);
        void sendFloat(const char* varName, float val);
        void sendInt(const char* varName, int val);
        void sendMat4(const char* varName, glm::mat4 mat);
        void sendMat3(const char* varName, glm::mat3 mat);
        void sendMat2(const char* varName, glm::mat2 mat);

        unsigned int getProgram();
        void setInt(char* varName, int pos);
};
