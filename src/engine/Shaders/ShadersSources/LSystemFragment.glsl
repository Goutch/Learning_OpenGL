#version 330
in vec2 uv;
in vec2 xy;
uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
const float interval=0.1;
out vec4 fragColor;
void main(){

    vec4 c=vec4(1-(xy.y/1000),1,0,1.);
    if (has_texture==1)
    {
        vec4 texColor0=texture(texture_0, uv);
        fragColor=texColor0*material_color*c;
    }
    else {
        fragColor=material_color*c;
    }

}