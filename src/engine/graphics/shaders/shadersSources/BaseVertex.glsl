#version 400 core

layout(location=1)in vec2 vertexPosition;
layout(location=4)in vec3 colors;
uniform mat4 transform;
out vec3 color;
void main()
{
    color=colors;
    gl_Position=transform*vec4(vertexPosition.xy,0.,1.);
}