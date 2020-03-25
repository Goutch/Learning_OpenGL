#version 330 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
in vec4 color;
out vec4 fragColor;
void main()
{
    fragColor=material_color*color;
}