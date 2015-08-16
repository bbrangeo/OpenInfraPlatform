#version 410

uniform sampler2D			texDiffuseMap;
uniform bool				bTerrainTextured;

in VertexToFragment
{
	vec4 position;
	vec3 worldPosition;
	vec3 worldNormal;
	vec3 localPosition;
} vtf;

layout (location = 0) out vec4 color;
layout (location = 1) out vec3 worldNormal;
layout (location = 2) out vec3 worldPosition;

void main()
{
	vec3 normal = normalize(vtf.worldNormal);

	if (!gl_FrontFacing) 
	{
		normal = -normal;
	}

	vec3 finalColor = vec3(0.7, 0.7, 0.7);

	if(bTerrainTextured)
	{
		vec2 uv =  vtf.localPosition.xy / 300;
		finalColor = texture(texDiffuseMap, vec2(uv)).xyz;
	}

	color = vec4(finalColor, 1.0);
	worldNormal = normal;
	worldPosition = vtf.worldPosition;
}