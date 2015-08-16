//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
#version 420

uniform mat4 WorldViewProjection;

layout(location = 0) in vec3	atv_position;
layout(location = 1) in vec3	atv_color;
layout(location = 2) in float	atv_size;

out VertexToGeometry 
{
	vec4 position;
	vec3 color;
	float size;
} vtg;

void main()
{
	vtg.position = WorldViewProjection * vec4(atv_position, 1.0);
	vtg.color = atv_color;
	vtg.size =  atv_size;

	gl_Position = WorldViewProjection * vec4( atv_position, 1.0);
}
