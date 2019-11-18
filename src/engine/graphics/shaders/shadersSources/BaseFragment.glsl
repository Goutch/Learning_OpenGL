#version 400 core
out vec4 fragColor;
in vec3 color;
void main()
{
    fragColor=vec4(color.rgb,1.);
}