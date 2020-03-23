#version 330 core

uniform vec4 material_color;

in vec4 color;
out vec4 fragColor;
void main()
{
    fragColor=material_color*color;
}