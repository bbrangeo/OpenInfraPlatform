//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
#version 420

uniform mat4 WorldViewProjection;	

layout(location = 0) in vec3		atv_position;
layout(location = 1) in vec2		atv_uv;

out VertexToFragment
{
	vec4 position;
	vec2 uv;
} vtf;

void main()
{
	vtf.position = WorldViewProjection * vec4(atv_position, 1.0);
	vtf.uv = atv_uv;

	gl_Position = WorldViewProjection * vec4(atv_position, 1.0);
}