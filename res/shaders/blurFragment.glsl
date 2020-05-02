#version 330
//https://learnopengl.com/Advanced-Lighting/Bloom
uniform sampler2D texture_0;
in vec2 uv;
out vec4 fragColor;
uniform float weight[10] = float[] (5.227027, 3.1945946, 2.1216216, 1.054054, 0.516216,0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);

void main()
{
    vec3 result = texture(texture_0, uv).rgb * weight[0]; // current fragment's contribution
    for(int j = 1;j < 5; ++j)
    {
        vec2 tex_offset = float(j) / textureSize(texture_0, 0); // gets size of single texel
        for(int i = 1; i < 10; ++i)
        {
            result += texture(texture_0, uv + vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
            result += texture(texture_0, uv- vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
        }

        for(int i = 1; i < 10; ++i)
        {
            result += texture(texture_0, uv + vec2(0.0, tex_offset.y * i)).rgb * weight[i];
            result += texture(texture_0, uv - vec2(0.0, tex_offset.y * i)).rgb * weight[i];
        }
    }
    result*=0.01;

   fragColor = vec4(result, 1.0);
}
