#version 330 core
//https://www.opengl-tutorial.org/intermediate-tutorials/tutorial-16-shadow-mapping/
//https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping
in vec4 position;
in vec2 uv;
in vec3 normal;
in vec3 frag_pos;
in vec4 shadow_coord;

uniform bool tonal_mapping;
uniform sampler2D texture_0;
uniform sampler2D normal_map;
uniform int has_texture;
uniform int has_normal_map;
uniform vec4 material_color;
uniform vec3 ambient_light;
//point
uniform int point_light_count;
uniform float point_light_radius[8];
uniform vec3 point_light_colors[8];
uniform vec3 point_light_positions[8];
uniform float shine_factor;
uniform float damp_factor;
uniform vec3 view_pos;
//directionnal
uniform int directional_light_count;
uniform vec3 directional_light_color;
uniform sampler2D directional_light_shadowMap;
uniform vec3 directional_light_direction;
out vec4 fragColor;

vec3 calculateLight(vec3 lightDir,vec3 color,vec3 n)
{

    vec3 ouputLight=vec3(0,0,0);
    float diffuse = max(dot(n, lightDir), 0.0);
    ouputLight+=diffuse*color;
    //specular
    if (shine_factor>0.0001)
    {
        vec3 to_view_dir=normalize(view_pos-frag_pos);
        vec3 reflectDir = reflect(-lightDir, n);
        float spec = pow(max(dot(to_view_dir, reflectDir), 0.0), damp_factor);
        ouputLight+= vec3(shine_factor * spec);
    }
    return ouputLight;
}
void main(){
    vec3 n=normal;
    if(has_normal_map==1){
        n=normal*texture(normal_map, uv).rgb;
    }
    n=normalize(n);
    vec3 light=ambient_light;
    //direcitonnal
    for (int i=0;i<directional_light_count;i++){
        vec3 normalizedLightDir=normalize(directional_light_direction);
        //is in shadowmap
        if (shadow_coord.x>0&&shadow_coord.x<1&&shadow_coord.y<1&&shadow_coord.y>0)
        {
            //is not in shadow
            if (texture(directional_light_shadowMap, shadow_coord.xy,0.005).z >= shadow_coord.z- 0.005){
                light+=calculateLight(normalizedLightDir,directional_light_color,n);
            }
            //else is in shadow do nothing
        }
        //outside of shadowmap
        else
        {
            light+=calculateLight(normalizedLightDir,directional_light_color,n);
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
            light+=calculateLight(lightDir,point_light_colors[i],n)*intensity;
        }
    }
    vec4 hdrColor;
    if (has_texture==1)
    {
        //texture
        vec4 textureColor=texture(texture_0, uv);
        hdrColor = textureColor*material_color*vec4(light,1.);
    }
    else {
        hdrColor=material_color*vec4(light,1.);
    }

    if(tonal_mapping) {
        fragColor = vec4(hdrColor.rgb / (hdrColor.rgb + vec3(1.0)), 1.0);
    }
    else {
        fragColor = hdrColor;
    }
}

