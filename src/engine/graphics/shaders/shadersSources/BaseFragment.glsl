#version 400 core
out vec4 fragColor;
in vec3 color;
in vec2 uvs;
uniform sampler2D texture_0;
uniform int has_texture;
void main()
{
    vec4 texColor0=texture(texture_0,uvs);
    vec4 texColor1=texture(texture_1,uvs);
    if(has_texture==1)
    {
        if(pow((uvs.x*2)-1,2)+pow((uvs.y*2)-1,2)<1)
        {
            fragColor=vec4(color.rgb,1.)*((1-uvs.x)*texColor1)+(uvs.x*texColor0);
        }
        else
        {
            fragColor=vec4(0.,0.,0.,0.);
        }
    }


}