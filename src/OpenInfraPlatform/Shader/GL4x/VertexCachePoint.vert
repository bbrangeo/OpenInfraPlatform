//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
#version 420

uniform mat4 World;		

layout(location = 0) in vec3	atv_position;
layout(location = 1) in vec3	atv_color;
layout(location = 2) in float	atv_size;

out VertexToGeometry 
{
	vec3 worldPosition;
	vec3 color;
	float size;
} vtg;

void main()
{
	vtg.worldPosition = (World   * vec4( atv_position, 1.0)).xyz;
	vtg.color = atv_color;
	vtg.size =  atv_size;

	gl_Position = vec4(atv_position, 1.0);
}