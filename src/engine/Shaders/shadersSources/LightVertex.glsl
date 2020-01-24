#version 400 core

//base
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 depth_bias_mat;

layout(location=0)in vec3 vertexPosition;
layout(location=2)in vec3 vertexNormal;
layout(location=1)in vec2 vertexUv;

out vec4 position;
out vec3 normal;
out vec2 uv;
out vec3 frag_pos;
out vec4 shadow_coord;
void main(){
    //texture
    uv=vertexUv;
    //Diffuselight
    position=transform*vec4(vertexPosition.xyz, 1.);
    normal=normalize(vertexNormal);
    frag_pos = position.xyz;
    normal = vertexNormal;

    //position
    gl_Position=projection*view*position;

    shadow_coord = depth_bias_mat *position;
}