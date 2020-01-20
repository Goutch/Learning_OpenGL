#version 400 core

//base
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

layout(location=0)in vec3 vertexPosition;
layout(location=2)in vec3 vertexNormal;
layout(location=1)in vec2 textureCoords;

out vec4 position;
out vec3 normal;
out vec2 uv;
out vec3 frag_pos;

void main(){
    //texture
    uv=textureCoords;
    //Diffuselight
    position=transform*vec4(vertexPosition.xyz, 1.);
    normal=vertexNormal;
    frag_pos = position.xyz;
    normal = vertexNormal;

    //position
    gl_Position=projection*view*position;
}