#version 330
uniform sampler2D texture_0;
in vec2 uv;
out vec4 fragColor;

void main()
{
    vec4 texColor0=texture(texture_0,uv);
    fragColor = vec4(1.0- texColor0.r,1.0-texColor0.g,1.0-texColor0.b ,1.0 );
}
