#version 400 core
out vec4 fragColor;
in vec3 vertex;
void main()
{
    fragColor=vec4(vertex.xyz,1.);
}