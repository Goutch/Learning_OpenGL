#version 400 core

//base
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
uniform int point_light_count;
uniform vec3 point_light_positions[4];
out vec3 to_point_light_directions[4];

layout(location=0)in vec3 vertexPosition;
layout(location=2)in vec3 vertexNormal;
layout(location=1)in vec2 textureCoords;

out vec4 position;
out vec3 normal;
out vec2 uv;
out vec3 to_camera_direction;


void main(){
    //texture
    uv=textureCoords;
    //Diffuselight
    position=transform*vec4(vertexPosition.xyz, 1.);
    normal=(transform*vec4(vertexNormal, 0.)).xyz;

    for (int i=0;i<point_light_count;i++)
    {
        to_point_light_directions[i]=point_light_positions[i]-position.xyz;
    }

    //SpecularLight
    to_camera_direction=(inverse(view)*vec4(0., 0., 0., 1.)).xyz-position.xyz;

    //position
    gl_Position=projection*view*position;
}