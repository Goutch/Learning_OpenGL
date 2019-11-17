#version 400 core

layout(location=0)in vec3 vertexPosition;
out vec3 vertex;
void main()
{
    vertex=vertexPosition;
    gl_Position=vec4(vertexPosition.xyz,1.);

}