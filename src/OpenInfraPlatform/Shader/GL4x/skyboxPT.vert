#version 410

#include "skyboxPT.glsl"

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
out VertexToFragment vtf;

uniform mat4 World;		
uniform mat4 WorldIT;				// inverse transposed	
uniform mat4 WorldViewProjection;

void main()
{	
	vtf.worldPosition = (World   * vec4( position, 1.0)).xyz;
	vtf.uv            = uv;

	gl_Position = WorldViewProjection * vec4( position, 1.0);
}
