#version 330 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in int vertex_data;//32bits total|18 bits for position/2 bits for uvs/4 bits occlusion/8 open
layout(location=3)in vec4 vertexColor;
out vec4 color;
vec2 vertex_uv[4]=vec2[4](
vec2(0, 0),
vec2(1, 0),
vec2(0, 1),
vec2(1, 1)
);
out vec2 tex_coord;
flat out int occlusion_case;
void main()
{
    vec3 position=vec3(float((vertex_data>>26)&0x3F),float((vertex_data>>20)&0x3F),float((vertex_data>>14)&0x3F));
    tex_coord=vertex_uv[(vertex_data>>12)&0x03];
    occlusion_case=(vertex_data>>8)&0xF;
    color=vertexColor;
    gl_Position=projection*view*transform*vec4(position, 1.);

}