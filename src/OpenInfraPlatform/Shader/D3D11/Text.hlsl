//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

SamplerState		samplerLinear;
Texture2D<float4>	font_map;

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

	float smoothness = 64.0f;
	float gamma = 2.2;

	float4 diffuseMaterialColor = font_map.Sample(samplerLinear, float2(vtf.uv.x, 1-vtf.uv.y), float2(0, 0));
	final.color = diffuseMaterialColor;

	// retrieve signed distance
	float sdf = diffuseMaterialColor.a;

	// perform adaptive anti-aliasing of the edges
	
	float w = clamp( smoothness * (abs(ddx(vtf.uv.x)) + abs(ddy(1-vtf.uv.y))), 0.0, 0.5);
	float a = smoothstep(0.5-w, 0.5+w, sdf);

	// gamma correction for linear attenuation
	a = pow(a, 1.0/gamma);

	final.color = float4(1, 1, 1, a);

	return final;
}