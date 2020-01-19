#version 400 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;


in vec2 uvs;
out vec4 fragColor;
void main()
{
    if(has_texture==1)
    {
        vec4 texColor0=texture(texture_0,uvs);
        fragColor=texColor0*material_color;
    }
    else{
        fragColor=material_color;
    }
}