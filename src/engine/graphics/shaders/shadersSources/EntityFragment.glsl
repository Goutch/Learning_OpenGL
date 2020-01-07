#version 400 core
out vec4 fragColor;
in vec3 color;
in vec2 uvs;
uniform sampler2D texture_0;
uniform int has_texture;
void main()
{
    if(has_texture==1)
    {
        vec4 texColor0=texture(texture_0,uvs);
        fragColor=texColor0*vec4(color.rgb,1.);
    }
    else{
        fragColor=vec4(color.rgb,1.);
    }
}