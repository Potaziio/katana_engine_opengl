#pragma once

#include "../components/Transform.hpp"
#include "../components/SpriteRenderer.hpp"

#include "../gameobject/Component.hpp"
#include "../gameobject/GameObject.hpp"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

class MeshRenderer : public Component {
    private:
        float width;
        float height;

        glm::vec3 color;

        unsigned int VAO, VBO, EBO;

        int POS_OFFSET = 0;
        int POS_SIZE = 3;

        int COLOR_OFFSET = POS_OFFSET;
        int COLOR_SIZE = 3;

        int VERTEX_SIZE = POS_SIZE;

        int VERTEX_SIZE_BYTES = VERTEX_SIZE * sizeof(float);

        float vertices[24]; 

        unsigned int indices[6] = {
            0, 1, 3,
            1, 2, 3
        };
    public:
        bool isEnabled;

        GameObject gameObject;

        MeshRenderer(float width, float height, glm::vec3 color, bool draw);
       
        unsigned int getVAO();
        unsigned int getEBO();
        unsigned int getVBO();

        void freeResources();

        float* getVertices();
        void generateVertices();
        void render();

        virtual ~MeshRenderer() {}
};
