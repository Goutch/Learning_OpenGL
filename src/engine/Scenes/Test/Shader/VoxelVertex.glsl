#version 330 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 vertexUv;
layout(location=2)in vec3 vertexNormal;
layout(location=3)in vec4 vertexColor;
layout(location=4)in vec4 vertexOcclusion;
out vec4 color;
out vec2 uv;
out vec4 occlusion;
void main()
{
    color=vertexColor;
    occlusion=vertexOcclusion;
    uv=vertexUv;
    gl_Position=projection*view*transform*vec4(vertexPosition,1.);
}