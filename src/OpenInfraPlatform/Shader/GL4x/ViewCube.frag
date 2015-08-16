//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

#version 420

uniform sampler2D			texDiffuseMap;

in VertexToFragment
{
	vec3 worldPosition;
	vec3 worldNormal;
	vec2 uv;
	vec3 pickColor;
} vtf;

out vec4 FragColor;

void main()
{
	vec2 uv = vtf.uv;
	vec3 diffuseMaterialColor =  texture(texDiffuseMap, uv).xyz;
	FragColor = vec4( diffuseMaterialColor, 1);
}