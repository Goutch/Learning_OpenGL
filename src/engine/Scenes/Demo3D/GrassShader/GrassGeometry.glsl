#version 330 core
#extension GL_ARB_geometry_shader4 : enable

layout (points) in;
layout (triangle_strip, max_vertices =3) out;
uniform float time;
uniform mat4 mvp;
in vec2 normal[];

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}
void main() {

    vec4 pos=gl_in[0].gl_Position;

    vec3 size=vec3(normal[0].y,rand(pos.zx),normal[0].x);

    gl_Position =mvp* (pos+vec4(size.x*0.1, 0,size.z*0.1, 0));
    EmitVertex();

    gl_Position = mvp*(pos+vec4(0, size.y, 0, 0));
    EmitVertex();

    gl_Position =mvp* (pos+vec4(-size.x*0.1, 0, -size.z*0.1, 0));
    EmitVertex();

    EndPrimitive();

}