#version 420

#include "positionTexture.glsl"

out VertexToFragment vtf;

void main()
{
	switch (gl_VertexID) 
	{
		case 0:
			gl_Position = vec4 (-1, 1, 0, 1);
			vtf.uv = vec2(0, 1);
			break;
		case 1:
			gl_Position = vec4 (-1, -1, 0, 1);
			vtf.uv = vec2(0, 0);
			break;
		case 2: 
			gl_Position = vec4 (1, 1, 0, 1);
			vtf.uv = vec2(1, 1);
			break;
		case 3: 
			gl_Position = vec4 (1, -1, 0, 1);
			vtf.uv = vec2(1, 0);
			break;
		default: 
			gl_Position = vec4 (0, 0, 0, 0);
			vtf.uv = vec2(0, 0);
			break;
    }
}