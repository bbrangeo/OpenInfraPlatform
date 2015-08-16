#version 410

#include <skybox.glsl>

in VertexToFragment vtf;
out vec4 FragColor;

uniform samplerCube skyboxCubeMap;

void main()
{
	// final
	vec3 finalColor = texture(skyboxCubeMap, vtf.worldPosition).xyz;   

	FragColor = vec4(finalColor.xyz, 1.0f);
}