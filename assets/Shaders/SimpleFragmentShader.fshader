#version 330 core

in vec4 color;
out vec4 fColor;
uniform vec3 tColor;

void main()
{
    fColor = vec4(tColor, 0.5);
}
