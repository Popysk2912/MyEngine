#version 330 core
out vec4 color;

uniform vec3 Color;

void main()
{
    color = vec4(Color, 1.0);
}