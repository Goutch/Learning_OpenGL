#version 400 core

layout(location=0)in vec2 vertexPosition;
layout(location=2)in vec2 texCoord;
layout(location=3)in vec3 colors;

uniform mat4 transform;
out vec3 color;
out vec2 uvs;
void main()
{
    uvs=texCoord;
    color=colors;
    gl_Position=transform*vec4(vertexPosition.xy,0.,1.);
}