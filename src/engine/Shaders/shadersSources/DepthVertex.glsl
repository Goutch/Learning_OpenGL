#version 330 core


layout(location = 0) in vec3 vertexPosition;

uniform mat4 space;
uniform mat4 transform;

void main(){
    gl_Position =  space *transform* vec4(vertexPosition,1);
}