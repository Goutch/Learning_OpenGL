#version 330 core
layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 vertexUv;
out vec2 uv;
void main()
{
    uv=vertexUv;
    gl_Position=vec4(vertexPosition.xyz,1.);
}