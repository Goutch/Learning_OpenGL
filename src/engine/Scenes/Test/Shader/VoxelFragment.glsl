#version 330 core

uniform vec4 material_color;
uniform sampler2D texture_0;
uniform int has_texture;
in vec2 uv;
in vec4 occlusion;
in vec4 color;
out vec4 fragColor;
const float occlusion_value=0.33;
void main()
{
    vec4 c=material_color*color;
    vec4 occluded_color;
    bool X=occlusion.x>=0.5;
    bool Y=occlusion.y>=0.5;
    bool Z=occlusion.z>=0.5;
    bool W=occlusion.w>=0.5;
    //Y---W
    //|   |
    //X---Z

    //o---o
    //|   |
    //o---o
    if (!X && !Y && !Z && !W)
    {
        occluded_color=c;
    }
    //o---o
    //|   |
    //x---o
    else if (X && !Y && !Z && !W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-(uv.y))*(1.-(uv.x)));
    }
    //x---o
    //|   |
    //o---o
    else if (!X && Y && !Z && !W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.y)*(1.-uv.x));
    }
    //o---o
    //|   |
    //o---x
    else if (!X && !Y && Z && !W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-uv.y)*(uv.x));

    }
    //o---x
    //|   |
    //o---o
    else if (!X && !Y && !Z && W)
    {
        occluded_color= mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.y)*(uv.x));
    }
    //x---o
    //|   |
    //x---o
    else if (X && Y && !Z && !W)
    {
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-uv.x));
    }
    //x---o
    //|   |
    //o---x
    else if (!X && Y && Z && !W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-uv.x)*uv.y)*mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.x)*(1.-(uv.y)));
    }
    //o---x
    //|   |
    //o---x
    else if (!X && !Y && Z && W)
    {
        occluded_color=  mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.x));
    }

    //o---x
    //|   |
    //x---o
    else if (X && !Y && !Z && W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.x)*(uv.y))*mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-(uv.x))*(1.-(uv.y)));
    }


    //x---x
    //|   |
    //o---o
    else if (!X && Y && !Z && W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (uv.y));
    }

    //o---o
    //|   |
    //x---x
    else if (X && !Y && Z && !W)
    {
        occluded_color=mix(c, vec4(c.rgb-(c.rgb*occlusion_value), 1), (1.-uv.y));
    }

    //x---o
    //|   |
    //x---x
    else if (X && Y && Z && !W)
    {
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, (uv.x)*(uv.y));
    }

    //x---x
    //|   |
    //o---x
    else if (!X && Y && Z && W)
    {
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, (1.-uv.x)*(1.-uv.y));
    }

    //o---x
    //|   |
    //x---x
    else if (X && !Y && Z && W)
    {
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, (1.-uv.x)*(uv.y));
    }
    //x---x
    //|   |
    //x---o
    else if (X && Y && !Z && W)
    {
        occluded_color=mix(vec4(c.rgb-(c.rgb*occlusion_value), 1), c, (uv.x)*(1.-uv.y));
    }
    //x---x
    //|   |
    //x---x
    else if (X&&Y&&Z&&W)
    {
        occluded_color=vec4(c.rgb-(c.rgb*occlusion_value), 1);
    }
    else {
        occluded_color=c;
    }
    fragColor=occluded_color;
}