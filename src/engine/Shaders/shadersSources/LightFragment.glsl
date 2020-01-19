#version 400 core

in vec4 position;
in vec2 uv;
in vec3 normal;
in vec3 to_camera_direction;
in vec3 to_point_light_directions[4];

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
//uniform int directionnal_light_count;
//uniform vec3 directional_light_colors[2] ;
//uniform vec3 directional_light_directions[2];


out vec4 fragColor;
void main(){

    //diffuse
    vec3 normalizedNormal=normalize(normal);
    vec3 diffuseLight=vec3(0.,0.,0.);
    vec3 specularLight=vec3(0.,0.,0.);
    //directionnalsLights
    //for(int i=0;i<directionnal_light_count;i++)
    //{
    //    vec3 normalizedLightDirection=normalize(directional_light_directions[i]);
//
    //    float lightValue=dot(normalizedNormal,-normalizedLightDirection);
    //    lightValue=max(lightValue,0.);
    //    diffuseLight+=directional_light_colors[i]*lightValue;
    //    //specular
//
    //    if(shine_factor>0.0001)
    //    {
    //        vec3 normalizedToCameraDirection=normalize(to_camera_direction);
//
    //        vec3 reflectedLightDirection=reflect(normalizedLightDirection,normalizedNormal);
//
    //        float specularReflection=dot(reflectedLightDirection,normalizedToCameraDirection);
    //        specularReflection=max(specularReflection,0.);
    //        float dampedReflection=pow(specularReflection,damp_factor);
    //        specularLight+=dampedReflection*shine_factor*directional_light_colors[i];
    //    }
    //}
    //pointLights
    for(int i=0;i<point_light_count;i++)
    {
        float dist=distance(point_light_positions[i],position.xyz);

        if(dist<point_light_radius[i])
        {
            float intensity=1-dist/point_light_radius[i];
            vec3 normalizedToLightDirection=normalize(to_point_light_directions[i]);

            float lightValue=dot(normalizedNormal,normalizedToLightDirection);
            lightValue=max(lightValue,0.);
            diffuseLight+=point_light_colors[i]*lightValue*intensity;
            //specular

            if(shine_factor>0.0001)
            {
                vec3 normalizedToCameraDirection=normalize(to_camera_direction);
                vec3 lightDirection=-normalizedToLightDirection;
                vec3 reflectedLightDirection=reflect(lightDirection,normalizedNormal);

                float specularReflection=dot(reflectedLightDirection,normalizedToCameraDirection);
                specularReflection=max(specularReflection,0.);
                float dampedReflection=pow(specularReflection,damp_factor);
                specularLight+=dampedReflection*shine_factor* point_light_colors[i]*intensity;
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