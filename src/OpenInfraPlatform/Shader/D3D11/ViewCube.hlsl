//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			WorldViewProjection;
Texture2D<float4>	texDiffuseMap;
SamplerState		sampler_;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float3 normal				: normal;
	float2 uv				    : uv;
	float3 pickColor		    : pickcolor;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float4 position				: SV_POSITION;
	float2 uv				    : uv;
	float3 pickColor		    : pickcolor;
};

//----------------------------------------------------------------------------
VertexToFragment VS_main (ApplicationToVertex app2vs)
{
	VertexToFragment vtf = (VertexToFragment)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.uv = app2vs.uv;
	vtf.pickColor = app2vs.pickColor;

	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

float4 PS_main (VertexToFragment vtf, bool frontFace : SV_IsFrontFace) 	: SV_Target0
{
	float3 diffuseMaterialColor = float4(texDiffuseMap.Sample(sampler_, float2(vtf.uv.x, vtf.uv.y), float2(0, 0)).xyz,1.0f);

	return float4(diffuseMaterialColor,1.0f);
}