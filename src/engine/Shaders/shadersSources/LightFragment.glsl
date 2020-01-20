#version 400 core

in vec4 position;
in vec2 uv;
in vec3 normal;
in vec3 to_camera_direction;
in vec3 frag_pos;

uniform sampler2D texture_0;
uniform int has_texture;
uniform vec4 material_color;
uniform vec3 ambient_light;
uniform int point_light_count;
uniform float point_light_radius[4];
uniform vec3 point_light_colors[4];
uniform vec3 point_light_positions[4] ;
uniform float shine_factor; //
uniform float damp_factor;
uniform vec3 view_pos;
//uniform int directionnal_light_count;
//uniform vec3 directional_light_colors[2] ;
//uniform vec3 directional_light_directions[2];


out vec4 fragColor;
void main(){

    //diffuse
    vec3 normalizedNormal=normalize(normal);
    vec3 diffuseLight=vec3(0.,0.,0.);
    vec3 specularLight=vec3(0.,0.,0.);

    //pointLights
    for(int i=0;i<point_light_count;i++)
    {
        float dist=distance(point_light_positions[i],position.xyz);

        if(dist<point_light_radius[i])
        {
            float intensity=1-dist/point_light_radius[i];
            vec3 norm = normalize(normal);
            vec3 lightDir = normalize(point_light_positions[i] - frag_pos);
            float diff = max(dot(norm, lightDir), 0.0);
            diffuseLight+=diff*point_light_colors[i]*intensity;
            //specular
            if(shine_factor>0.0001)
            {
                vec3 viewDir = normalize(view_pos - frag_pos);
                vec3 reflectDir = reflect(-lightDir, norm);
                float spec = pow(max(dot(viewDir, reflectDir), 0.0),damp_factor);
                specularLight+= vec3(shine_factor * spec)*intensity;
            }
        }
    }
    vec4 light=vec4(ambient_light+diffuseLight+specularLight,1.);
    if(has_texture==1)
    {
        //texture
        vec4 textureColor=texture(texture_0, uv);
        fragColor=textureColor*material_color*light;
    }
    else{
        fragColor=material_color*light;
    }

}