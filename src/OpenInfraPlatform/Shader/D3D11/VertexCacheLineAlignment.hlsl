#include "VertexCacheLine.hlsl"

//----------------------------------------------------------------------------
struct ApplicationToVertexAlignment
{
	float3 position				: position;
	float3 color				: color;
	float  size				    : size;
	uint   id					: id;
};

int selectedIndex;
int hoveredIndex;

//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
VertexToGeometry VS_main_Alignment(ApplicationToVertexAlignment app2vs)
{
	VertexToGeometry vtf = (VertexToGeometry)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.color = app2vs.color;
	vtf.size = app2vs.size;

	if (selectedIndex != -1 && selectedIndex == app2vs.id)
		vtf.color = float3(1, 0.66, 0.1);
	if (hoveredIndex != -1 && hoveredIndex == app2vs.id)
	{
		vtf.color = float3(1, 1, 1);
		vtf.size *= 2;
	}

	return vtf;
}