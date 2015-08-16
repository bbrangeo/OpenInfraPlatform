//---------------------------------------------------------------------------//
// Vertex Shader: GBuffer
//---------------------------------------------------------------------------//

#version 420

uniform mat4 WorldViewProjection;
uniform mat4 World;
uniform mat4 WorldIT;

layout(location = 0) in vec3		atv_position;
layout(location = 1) in vec3		atv_normal;
layout(location = 2) in vec2		atv_uv;

out VertexToFragment
{
	vec3 worldPosition;
	vec3 worldNormal;
	vec3 localPosition;
} vtf;

void main()
{
	vtf.worldPosition = (World * vec4( atv_position, 1.0)).xyz;	
	vtf.worldNormal = (WorldIT * vec4( atv_normal, 1.0)).xyz;
	vtf.localPosition = atv_position;

	gl_Position = WorldViewProjection * vec4(atv_position, 1.0);
}