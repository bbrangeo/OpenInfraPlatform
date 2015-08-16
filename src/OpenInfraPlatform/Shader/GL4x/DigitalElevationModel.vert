//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
#version 420

uniform mat4			WorldViewProjection;
uniform mat4			World;
uniform mat4			WorldIT;

//----------------------------------------------------------------------------
layout(location = 0) in vec3 atv_position;
layout(location = 1) in vec3 atv_normal;
layout(location = 2) in vec2 atv_uv;

out VertexToFragment
{
	vec4 position;
	vec3 worldPosition;
	vec3 worldNormal;
	vec2 uv;
	vec3 localPosition;
	float height;
} vtf;

void main()
{
	vtf.height = atv_position.z;
	vtf.position = WorldViewProjection * vec4( atv_position, 1.0);
	vtf.worldPosition = (World * vec4(atv_position, 1)).xyz;
	vtf.worldNormal = (WorldIT * vec4(atv_normal, 1.0)).xyz;
	vtf.uv = atv_uv;
	vtf.localPosition = atv_position;

	gl_Position = WorldViewProjection * vec4( atv_position, 1.0);
}