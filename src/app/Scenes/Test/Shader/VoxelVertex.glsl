#version 330 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 vertexUv;
layout(location=2)in vec3 vertexNormal;
layout(location=3)in vec4 vertexColor;
layout(location=4)in int faceOcclusion;
out vec4 color;
out vec2 tex_coord;
flat out int occlusion_case;
void main()
{
    color=vertexColor;
    occlusion_case=faceOcclusion;
    tex_coord=vertexUv;
    gl_Position=projection*view*transform*vec4(vertexPosition,1.);
}