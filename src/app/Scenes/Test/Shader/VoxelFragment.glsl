#version 330 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
varying in vec2 tex_coord;
flat in int occlusion_case;
in vec4 color;
out vec4 fragColor;
const float occlusion_value=0.33;
void main()
{
    vec4 c=material_color*color;
    vec4 occluded_color;

    //Y---W
    //|   |
    //X---Z
    vec2 uv=tex_coord*5;
    switch (occlusion_case)
    {
        //o---o
        //|   |
        //o---o
        //if (!X && !Y && !Z && !W)
        case 0:{
        occluded_color=c;
        break; }
        //o---o
        //|   |
        //x---o
        //if (X && !Y && !Z && !W)
        case 1:{
        float v=(1.-(uv.y))*(1.-(uv.x));
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //o---o
        //if (!X && Y && !Z && !W)
        case 2:{
        float v=(uv.y)*(1.-uv.x);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //x---o
        //if (X && Y && !Z && !W)
        case 3:{
        float v= (1.-uv.x);
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---o
        //|   |
        //o---x
        // if (!X && !Y && Z && !W)
        case 4:{
        float v=(1.-uv.y)*(uv.x);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---o
        //|   |
        //x---x
        //if (X && !Y && Z && !W)
        case 5:{
        float v=(1.-uv.y);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //o---x
        //if (!X && Y && Z && !W)
        case 6:{
        float v1=(1.-uv.x)*uv.y;
        float v2=(uv.x)*(1.-(uv.y));
        occluded_color=mix(c, vec4((c.rgb)-(c.rgb*occlusion_value), 1), v1)*mix(c, vec4((c.rgb)-(c.rgb*occlusion_value), 1), v2);
        break; }
        //x---o
        //|   |
        //x---x
        //if (X && Y && Z && !W)
        case 7:{
        float v=(uv.x)*(uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //o---x
        //|   |
        //o---o
        //if (!X && !Y && !Z && W)
        case 8:{
        float v=(uv.y)*(uv.x);
        occluded_color= mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---x
        //|   |
        //x---o
        //if (X && !Y && !Z && W)
        case 9:{
        float v1=(uv.x)*(uv.y);
        float v2=(1.-(uv.x))*(1.-(uv.y));
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v1)*mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v2);
        break; }
        //x---x
        //|   |
        //o---o
        //if (!X && Y && !Z && W)
        case 10:{
        float v=(uv.y);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---x
        //|   |
        //x---o
        //if (X && Y && !Z && W)
        case 11:{
        float v=(uv.x)*(1.-uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //o---x
        //|   |
        //o---x
        //if (!X && !Y && Z && W)
        case 12:{
        float v=(uv.x);
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---x
        //|   |
        //x---x
        //if (X && !Y && Z && W)
        case 13:{
        float v=(1.-uv.x)*(uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //x---x
        //|   |
        //o---x
        //if (!X && Y && Z && W)
        case 14:{
        float v= (1.-uv.x)*(1.-uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //x---x
        //|   |
        //x---x
        //if (X&&Y&&Z&&W)
        case 15:{
        occluded_color=vec4(c.rgb-(c.rgb*occlusion_value), 1);
        break; }
    }
    fragColor=occluded_color;
}