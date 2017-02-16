//Based on the example in the book of shader
//https://thebookofshaders.com/07/

#version 150

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform sampler2D tex0;
uniform sampler2D tex1;

in vec4 vTexCoord0;

out vec4 oColor;

void main( void ) {
    
    vec4 color0 = texture(tex0, vTexCoord0.st);
    vec4 color1 = texture(tex1, vTexCoord0.st);
    
    vec2 st = gl_FragCoord.xy / u_resolution.y;
    float colorMix = 0.0;
    
    vec2 mousePos = vec2(u_mouse.x, u_resolution.y-u_mouse.y);
    
    colorMix = distance(st,mousePos / u_resolution);
    
    vec4 result = mix(color0, color1, colorMix);
    
    oColor.rgb = result.rgb;
    oColor.a = 1.0;
}