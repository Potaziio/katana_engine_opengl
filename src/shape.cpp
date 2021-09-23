#include "../include/Shape.hpp"

GLuint Shape::VertexBuffer;

const GLfloat Shape::Triangle[] = 
{
    -0.3f, -0.3f, 0.0f,
    0.3f, -0.3f, 0.0f,
    0.0f, 0.3f, 0.0f
};

void Shape::SetTriangleVertices()
{
    GLuint VertexArrayID;

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    GLuint VertexBuffer;

    glGenBuffers(1, &VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Shape::Triangle), Shape::Triangle, GL_STATIC_DRAW);

    Shape::VertexBuffer = VertexBuffer;
}

void Shape::DisplayTriangle(LoadShaders TriangleShader, float r, float g, float b)
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, Shape::VertexBuffer);

    glVertexAttribPointer
        (
         0,
         3,
         GL_FLOAT,
         GL_FALSE,
         0,
         (void*)0
        );

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    glUseProgram(TriangleShader.shader);
    GLint uniform = glGetUniformLocation(TriangleShader.shader, "tColor");
    glUniform3f(uniform, r, g, b);
}
