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
void main(){

    vec3 normalizedNormal=normalize(normal);
    vec3 diffuseLight=vec3(0., 0., 0.);
    vec3 specularLight=vec3(0., 0., 0.);
    //direcitonnal
    for (int i=0;i<directional_light_count;i++){
        if (shadow_coord.x>0&&shadow_coord.x<1&&shadow_coord.y<1&&shadow_coord.y>0)
        {

            if (texture(directional_light_shadowMap, shadow_coord.xy).z >= shadow_coord.z-0.005){
                float intensity=dot(normalizedNormal,normalize(directional_light_direction));
                intensity=max(intensity,0.);
                diffuseLight+=directional_light_color*intensity;
                if(shine_factor>0.0001)
                {
                    vec3 viewDir = normalize(view_pos - frag_pos);
                    vec3 reflectDir = reflect(-directional_light_direction, normalizedNormal);
                    float spec = pow(max(dot(viewDir, reflectDir), 0.0), damp_factor);
                    specularLight+= vec3(shine_factor * spec)*intensity;
                }
            }
        }
        else
        {
            float lightValue=dot(normalizedNormal,normalize(directional_light_direction));
            lightValue=max(lightValue,0.);
            diffuseLight+=directional_light_color*lightValue;

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
            float diff = max(dot(normalizedNormal, lightDir), 0.0);
            diffuseLight+=diff*point_light_colors[i]*intensity;
            //specular
            if (shine_factor>0.0001)
            {
                vec3 viewDir = normalize(view_pos - frag_pos);
                vec3 reflectDir = reflect(-lightDir, normalizedNormal);
                float spec = pow(max(dot(viewDir, reflectDir), 0.0), damp_factor);
                specularLight+= vec3(shine_factor * spec)*intensity;
            }
        }
    }
    vec4 light=vec4(ambient_light+diffuseLight+specularLight, 1.);
    if (has_texture==1)
    {
        //texture
        vec4 textureColor=texture(texture_0, uv);
        fragColor=textureColor*material_color*light;
    }
    else {
        fragColor=material_color*light;
    }


}