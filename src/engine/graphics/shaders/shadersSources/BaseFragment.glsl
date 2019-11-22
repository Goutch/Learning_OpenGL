#version 400 core
out vec4 fragColor;
in vec3 color;
in vec2 uvs;
uniform sampler2D texture_0;
uniform sampler2D texture_1;
void main()
{
    vec4 texColor0=texture(texture_0,uvs);
    vec4 texColor1=texture(texture_1,uvs);
    fragColor=((1-uvs.x)*texColor1)+(uvs.x*texColor0);//*vec4(color.rgb,1.);
}