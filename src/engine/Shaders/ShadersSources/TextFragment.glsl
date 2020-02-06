#version 330 core

uniform vec4 material_color;
in vec2 uv;

uniform sampler2D texture_0;
uniform int has_texture;
out vec4 fragColor;
void main()
{
    if (has_texture==1)
    {
        vec4 texColor0=texture(texture_0, uv);
        if(texColor0.r==0) {
            fragColor=vec4(0,0,0,0);
        }
        else {
            fragColor=texColor0*material_color;
        }
    }
    else {
        fragColor=material_color;
    }

}