#version 400 core
uniform mat4 projection_mat;
uniform mat4 view_mat;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 texCoord;

layout(location=3)in vec4 colors;

out vec4 color;
out vec2 uvs;
void main()
{
    uvs=texCoord;
    color=colors;
    gl_Position=projection_mat*view_mat*transform*vec4(vertexPosition.xyz,1.);
}