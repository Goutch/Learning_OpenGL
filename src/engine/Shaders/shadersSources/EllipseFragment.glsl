#version 330 core

uniform vec4 material_color;
in vec2 uv;
out vec4 fragColor;
void main()
{
    vec2 coord=uv-.5;
    if (distance(coord, vec2(0, 0))>0.5)
    {
            fragColor=vec4(0, 0, 0, 0);
    }
    else
    {
        fragColor=material_color;
    }
}