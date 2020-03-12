#version 330 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
in vec2 uv;
out vec4 fragColor;
void main()
{
    if(has_texture==1)
    {
        vec4 texColor0=texture(texture_0,vec2((-(uv.x-0.5))+0.5,uv.y));
        fragColor=texColor0*material_color;
    }
    else{
        fragColor=material_color;
    }
}
