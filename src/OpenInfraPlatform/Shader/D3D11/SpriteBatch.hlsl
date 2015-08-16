//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

SamplerState		samplerLinear;
Texture2D<float4>	texDiffuseMap;

float4x4			WorldViewProjection;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float2 uv					: uv;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float4 position				: SV_POSITION;
	float2 uv					: uv;
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

	float4 diffuseMaterialColor = texDiffuseMap.Sample(samplerLinear, float2(vtf.uv.x, vtf.uv.y), float2(0, 0));

	final.color = diffuseMaterialColor;

	// colorkey
	if(	final.color.r == 1.0 &&
		final.color.g == 0.0 &&
		final.color.b == 1.0 )
		discard;

	// when user is hovering
	//final.color.r =  72.0f / 255.0f;
	//final.color.g = 183.0f / 255.0f;
	//final.color.b = 231.0f / 255.0f;

	final.color.a = diffuseMaterialColor.r;
	
	return final;
}