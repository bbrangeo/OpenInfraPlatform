//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
#version 420

#include "drawQuad.glsl"

/*
struct ApplicationToVertex
{
	vec3 position;
	vec2 uv;
};
in ApplicationToVertex atv;
*/
layout (location = 0) in vec3 atv_position;
layout (location = 1) in vec2 atv_uv;
out VertexToFragment vtf;

uniform mat4 WorldViewProjection;

void main()
{	
	vtf.uv			= atv_uv;

	gl_Position = WorldViewProjection * vec4( atv_position, 1.0);
}