#version 330 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=3)in vec4 vertexColor;

out vec4 color;

void main()
{
    color=vertexColor;
    gl_Position=projection*view*transform*vec4(vertexPosition,1.);
}