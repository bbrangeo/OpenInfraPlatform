//---------------------------------------------------------------------------//
// Vertex Shader
//---------------------------------------------------------------------------//

#version 420

uniform mat4 World;		
uniform mat4 WorldIT;	
uniform mat4 WorldViewProjection;	

layout(location = 0) in vec3		atv_position;
layout(location = 1) in vec3		atv_color;
layout(location = 2) in vec3		atv_normal;

out VertexToFragment
{
	vec3 worldPosition;
	vec3 color;
	vec3 worldNormal;
} vtf;

void main()
{
	vtf.worldPosition = (World * vec4( atv_position, 1.0)).xyz;	
	vtf.worldNormal = (WorldIT * vec4( atv_normal, 1.0)).xyz;
	vtf.color = atv_color;

	gl_Position = WorldViewProjection * vec4(atv_position, 1.0);
}