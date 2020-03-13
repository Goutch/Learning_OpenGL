#version 330
uniform sampler2D texture_0;
uniform vec2 resolution;
in vec2 uv;
out vec4 fragColor;

void main()
{

    vec4 n[9];
    float w = 1.0/resolution.x;
    float h = 1.0/resolution.y;

    n[0] = texture(texture_0, uv + vec2( -w, -h));
    n[1] = texture(texture_0, uv + vec2(0.0, -h));
    n[2] = texture(texture_0, uv + vec2(  w, -h));
    n[3] = texture(texture_0, uv + vec2( -w, 0.0));
    n[4] = texture(texture_0, uv);
    n[5] = texture(texture_0, uv + vec2(  w, 0.0));
    n[6] = texture(texture_0, uv + vec2( -w, h));
    n[7] = texture(texture_0, uv + vec2(0.0, h));
    n[8] = texture(texture_0, uv + vec2(  w, h));

    vec4 sobel_edge_h = n[2] + (2.0*n[5]) + n[8] - (n[0] + (2.0*n[3]) + n[6]);
    vec4 sobel_edge_v = n[0] + (2.0*n[1]) + n[2] - (n[6] + (2.0*n[7]) + n[8]);
    vec4 sobel = sqrt((sobel_edge_h * sobel_edge_h) + (sobel_edge_v * sobel_edge_v));

    fragColor = vec4( 1.0 - sobel.rgb, 1.0 );
}
