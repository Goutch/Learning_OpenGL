#version 400 core

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec3 colors;
out vec3 color;
void main()
{
    color=colors;
    gl_Position=vec4(vertexPosition.xyz,1.);

}