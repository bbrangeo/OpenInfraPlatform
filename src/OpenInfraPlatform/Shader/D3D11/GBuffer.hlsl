//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			WorldViewProjection;
float4x4			World;
float4x4			WorldIT;


Texture2D<float4>	texDiffuseMap;
SamplerState		sampler_;
bool				bTerrainTextured;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float3 normal				: normal;
	float2 uv				    : uv;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float4 position				: SV_POSITION;
	float3 worldPosition        : position;
	float3 worldNormal			: normal;
	float3 localPosition        : position2;
};

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
struct FragmentToGBuffer
{
	float4 color				: SV_Target0;
	float3 worldNormal			: SV_Target1;
	float3 worldPosition        : SV_Target2;
};

//----------------------------------------------------------------------------
VertexToFragment VS_main(ApplicationToVertex app2vs)
{
	VertexToFragment vtf = (VertexToFragment)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.worldPosition = mul(float4(app2vs.position, 1), World).xyz;
	vtf.worldNormal = mul(float4(app2vs.normal, 1.0), WorldIT).xyz;
	vtf.localPosition = app2vs.position;

	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

FragmentToGBuffer PS_main(VertexToFragment vtf, bool frontFace : SV_IsFrontFace)
{
	float3 normal = normalize(vtf.worldNormal);

	if (!frontFace)
	{
		normal = -normal;
	}

	float3 finalColor = float3(0.7, 0.7, 0.7);

	if (bTerrainTextured)
	{
		float2 uv = vtf.localPosition.xy / 300;
		finalColor = texDiffuseMap.Sample(sampler_, uv, float2(0, 0));
	}

	FragmentToGBuffer output;
	output.color = float4(finalColor, 1.0f);
	output.worldNormal = normal;
	output.worldPosition = vtf.worldPosition;

	return  output;
}