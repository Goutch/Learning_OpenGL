#version 330 core
uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

layout(location=0)in vec3 vertexPosition;
layout(location=1)in uint vertex_uv_index;
layout(location=3)in vec4 vertexColor;
layout(location=4)in uint faceOcclusion;
out vec4 color;
vec2 vertex_uv[4]=vec2[4](
vec2(0, 0),
vec2(1, 0),
vec2(0, 1),
vec2(1, 1)
);
out vec2 tex_coord;
flat out uint occlusion_case;
void main()
{
    color=vertexColor;
    occlusion_case=faceOcclusion;
    tex_coord=vertex_uv[vertex_uv_index];
    gl_Position=projection*view*transform*vec4(vertexPosition, 1.);
}