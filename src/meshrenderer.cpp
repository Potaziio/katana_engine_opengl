#include "../include/components/MeshRenderer.hpp"

void MeshRenderer::generateVertices() {
    vertices[0] = width;      // X
    vertices[1] = height;     // Y
    vertices[2] = 0.0f;
    vertices[3] = color.x;
    vertices[4] = color.y;
    vertices[5] = color.z;
    vertices[6] = width;      // X
    vertices[7] = -height;    // Y
    vertices[8] = 0.0f;
    vertices[9] = color.x;
    vertices[10] = color.y;
    vertices[11] = color.z;
    vertices[12] = -width;    // X
    vertices[13] = -height;   // Y
    vertices[14] = 0.0f;
    vertices[15] = color.x;
    vertices[16] = color.y;
    vertices[17] = color.z;
    vertices[18] = -width;    // X
    vertices[19] = height;    // Y
    vertices[20] = 0.0f;
    vertices[21] = color.x;
    vertices[22] = color.y;
    vertices[23] = color.z;
}

float* MeshRenderer::getVertices() {
    return vertices;
}

unsigned int MeshRenderer::getVAO(){
    return VAO; 
}


unsigned int MeshRenderer::getEBO(){
    return EBO; 
}

unsigned int MeshRenderer::getVBO(){
    return VBO;     
}

void MeshRenderer::freeResources() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void MeshRenderer::render() {
    if (isEnabled) {
        glBindVertexArray(VAO);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        glBindVertexArray(0);
    }
}

MeshRenderer::MeshRenderer(float width, float height, glm::vec3 color,  bool draw) : width(width), height(height), color(color), isEnabled(draw) {
    generateVertices();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    // VBO set up
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    // EBO set up
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attributes
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind VAO
    glBindVertexArray(0);
}
