//----------------------------------------------------------------------------
// Geometry Shader
//----------------------------------------------------------------------------

#version 420

uniform mat4 View;				
uniform mat4 Projection;
uniform vec2 Viewport;			// x = width, y = height
uniform vec4 Positions[4];

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

in VertexToGeometry
{
	vec3 worldPosition;
	vec3 color;
	float size;
} inputG[1];
 
out GeometryToFragment
{
	vec4 position;
	vec3 color;
} outputG;

void main()
{
	float g_pointSize = inputG[0].size;

	float fSizeX = (g_pointSize/Viewport.x)/4;
	float fSizeY = (g_pointSize/Viewport.y)/4;

    for(int i = 0; i < 4; i++)
	{
		vec4 outPos = View   * vec4( inputG[0].worldPosition, 1.0);
		outputG.position = Projection * outPos;
		gl_Position = Projection * outPos;
		
		// ideal wäre wenn die pixel positon genau auf ein pixel-zentrum fallen würde
		vec2 l_vCurrScreenPosition = outputG.position.xy / outputG.position.w;
		float z = outputG.position.z / outputG.position.w;
		vec2 l_vCurrPixelPosition       = l_vCurrScreenPosition * Viewport.xy * 0.5;
		int x = int(l_vCurrPixelPosition.x);
		int y = int(l_vCurrPixelPosition.y);
		l_vCurrPixelPosition.x = x + 0.5;// round(l_vCurrPixelPosition.x);
		l_vCurrPixelPosition.y = y + 0.5;//round(l_vCurrPixelPosition.y);

		// wie wärde die ideelae Bildschirmposition [0;1]?
		l_vCurrScreenPosition = l_vCurrPixelPosition * (1.0f / (Viewport.xy/2)) * outputG.position.w;

		// nochmal - jetzt idealle Positon verwenden, aber alte Tiefe beibehalten
		l_vCurrScreenPosition      = outputG.position.xy / outputG.position.w;
		outputG.position.xy = l_vCurrScreenPosition;
		outputG.position.w = 1;
		outputG.position.z = z;

		// Pixel nach der Projektion vergrößern auf gewünschte größe

		float zoverNear = 1;//(outPos.z)/g_ClipPlanes.x;
		fSizeX = 1.0f/Viewport.x * 2.0 * g_pointSize;
		fSizeY = 1.0f/Viewport.y * 2.0 * g_pointSize;
		vec4 posSize =     vec4( Positions[i].x*fSizeX,
								 Positions[i].y*fSizeY,
								 0,
								 0 );
		
		outputG.position += posSize;
		outputG.color = inputG[0].color;
		gl_Position = outputG.position;

		// done with the vertex
		EmitVertex();
	}
	
	EndPrimitive();
}