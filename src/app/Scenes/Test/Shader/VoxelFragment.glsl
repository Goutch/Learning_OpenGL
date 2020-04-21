#version 330 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
varying in vec2 tex_coord;
flat in uint occlusion_case;
in vec4 color;
out vec4 fragColor;
const float occlusion_value=0.15;
void main()
{
    vec4 c=material_color*color;
    vec4 occluded_color;
    vec2 uv=tex_coord;

    switch (occlusion_case)
    {
        //o---o
        //|   |
        //o---o
        case 0:{
        occluded_color=c;
        break; }
        //o---o
        //|   |
        //x---o
        case 1:{
        float v=sqrt(pow((1.-(uv.y)),2)*pow((1.-(uv.x)),2));
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //o---o
        case 2:{
        float v=sqrt(pow((uv.y),2)*pow((1.-uv.x),2));
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //x---o
        case 3:{
        float v= (1.-uv.x);
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---o
        //|   |
        //o---x
        case 4:{
        float v=sqrt(pow((1.-uv.y),2)*pow((uv.x),2));
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---o
        //|   |
        //x---x
        case 5:{
        float v=(1.-uv.y);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---o
        //|   |
        //o---x
        case 6:{
        float v1=distance(uv.x,uv.y);
        float v2=distance(1.-(uv.x),1.-(uv.y));
        occluded_color=(mix(c, vec4((c.rgb)-(c.rgb*occlusion_value), 1), v1)+mix(c, vec4((c.rgb)-(c.rgb*occlusion_value), 1), v2))*0.5;
        break; }
        //x---o
        //|   |
        //x---x
        case 7:{
        float v=(uv.x)*(uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //o---x
        //|   |
        //o---o
        case 8:{
        float v=sqrt(pow((uv.y),2)*pow((uv.x),2));
        occluded_color= mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---x
        //|   |
        //x---o
        case 9:{
        float v1=distance(1.-uv.x,uv.y);
        float v2=distance(uv.x,1.-uv.y);
        occluded_color=(mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v1)+mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v2))*0.5;
        break; }
        //x---x
        //|   |
        //o---o
        case 10:{
        float v=(uv.y);
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //x---x
        //|   |
        //x---o
        case 11:{
        float v=(uv.x)*(1.-uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //o---x
        //|   |
        //o---x
        case 12:{
        float v=(uv.x);
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), v);
        break; }
        //o---x
        //|   |
        //x---x
        case 13:{
        float v=(1.-uv.x)*(uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //x---x
        //|   |
        //o---x
        case 14:{
        float v= (1.-uv.x)*(1.-uv.y);
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, v);
        break; }
        //x---x
        //|   |
        //x---x
        case 15:{
        occluded_color=vec4(c.rgb-(c.rgb*occlusion_value), 1);
        break; }
    }
    fragColor=occluded_color;
}