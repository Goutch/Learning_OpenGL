#version 330
uniform mat4 projection;

uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in vec2 vertexUv;
out vec2 uv;
out vec2 xy;
void main() {
    uv=vertexUv;
    vec4 pos=transform*vec4(vertexPosition.xyz,1.);
    xy=pos.xy;
    gl_Position=projection*pos;
}
