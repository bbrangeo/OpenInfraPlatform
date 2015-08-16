#version 420

#include <positionTexture.glsl>

in VertexToFragment vtf;

out vec4 FragColor;

void main(void)
{
	vec4 top = vec4(  40.0/255.0,  40.0/255.0,  40.0/255.0, 1.0 );
	vec4 bottom	= vec4( 153.0/255.0, 160.0/255.0, 163.0/255.0, 1.0 );

	FragColor = mix(top, bottom, vtf.uv.y);
}