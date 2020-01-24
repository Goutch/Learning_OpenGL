#version 330 core


layout(location = 0) in vec3 vertexPosition;

uniform mat4 light_space_matrix;
uniform mat4 transform;

void main(){
    gl_Position =  light_space_matrix *transform* vec4(vertexPosition,1);
}