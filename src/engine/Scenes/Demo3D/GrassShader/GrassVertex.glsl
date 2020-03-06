#version 330 core

uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=2)in vec2 vertexNormal;

out vec2 normal;
void main(){
    normal=vertexNormal;
    gl_Position=vec4(vertexPosition.xyz,1.);

}