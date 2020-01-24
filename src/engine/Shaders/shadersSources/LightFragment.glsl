#version 400 core

in vec4 position;
in vec2 uv;
in vec3 normal;
in vec3 to_camera_direction;
in vec3 frag_pos;
in vec4 shadow_coord;

uniform sampler2D texture_0;
uniform int has_texture;
uniform vec4 material_color;
uniform vec3 ambient_light;
//point
uniform int point_light_count;
uniform float point_light_radius[4];
uniform vec3 point_light_colors[4];
uniform vec3 point_light_positions[4];
uniform float shine_factor;//
uniform float damp_factor;
uniform vec3 view_pos;
//directionnal
uniform int directional_light_count;
uniform vec3 directional_light_color;
uniform sampler2D directional_light_shadowMap;
uniform vec3 directional_light_direction;


out vec4 fragColor;
vec3 calculateLight(vec3 lightDir,vec3 color)
{
    vec3 ouputLight=vec3(0,0,0);
    float diffuse = max(dot(normal, lightDir), 0.0);
    ouputLight+=diffuse*color;
    //specular
    if (shine_factor>0.0001)
    {
        vec3 viewDir = normalize(view_pos - frag_pos);
        vec3 reflectDir = reflect(-lightDir, normal);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), damp_factor);
        ouputLight+= vec3(shine_factor * spec);
    }
    return ouputLight;
}
void main(){

    vec3 light=ambient_light;
    //direcitonnal
    for (int i=0;i<directional_light_count;i++){
        vec3 normalizedLightDir=normalize(directional_light_direction);
        if (shadow_coord.x>0&&shadow_coord.x<1&&shadow_coord.y<1&&shadow_coord.y>0)
        {
            if (texture(directional_light_shadowMap, shadow_coord.xy).z >= shadow_coord.z-0.005){
                light+=calculateLight(normalizedLightDir,directional_light_color);
            }
            //else shadow
        }
        //outside of shadowmap
        else
        {
            light+=calculateLight(normalizedLightDir,directional_light_color);
        }
    }

    //pointLights
    for (int i=0;i<point_light_count;i++)
    {
        float dist=distance(point_light_positions[i], position.xyz);
        if (dist<point_light_radius[i])
        {
            float intensity=1-dist/point_light_radius[i];
            vec3 lightDir = normalize(point_light_positions[i] - frag_pos);
            light+=calculateLight(lightDir,point_light_colors[i])*intensity;
        }
    }

    if (has_texture==1)
    {
        //texture
        vec4 textureColor=texture(texture_0, uv);
        fragColor=textureColor*material_color*vec4(light,1.);
    }
    else {
        fragColor=material_color*vec4(light,1.);
    }


}
