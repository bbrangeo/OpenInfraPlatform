//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			WorldViewProjection;
SamplerState		textureSampler;
Texture2D<float3>	texQuadMap;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position : position;
	float2 uv		: uv;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float4 position	: SV_POSITION;
	float2 uv		: uv;
};

//----------------------------------------------------------------------------
VertexToFragment VS_main (ApplicationToVertex app2vs)
{
   VertexToFragment vtf = (VertexToFragment)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1), WorldViewProjection);
	vtf.uv = app2vs.uv;
	
	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------
struct FragmentToPixel
{
	float4 color				: SV_Target0;
};

FragmentToPixel PS_main (VertexToFragment vtf, bool frontFace : SV_IsFrontFace)
{
	FragmentToPixel final;

	final.color = float4(texQuadMap.Sample(textureSampler, vtf.uv, float2(0, 0)), 1.0f);

	return final;
}