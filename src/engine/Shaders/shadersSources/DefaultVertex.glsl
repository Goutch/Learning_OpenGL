#version 400 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 vertexUv;
out vec2 uv;
void main()
{
    uv=vertexUv;
    gl_Position=projection*view*transform*vec4(vertexPosition.xyz,1.);
}