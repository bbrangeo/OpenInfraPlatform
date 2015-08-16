//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------
#version 420

#include "drawQuad.glsl"

in VertexToFragment vtf;
out vec4 FragColor;
uniform sampler2D texQuadMap;

void main()
{
	// final
	vec3 finalColor = texture2D(texQuadMap, vtf.uv).xyz;

	FragColor = vec4(finalColor.xyz, 1.0f);
}