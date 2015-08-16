//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			WorldViewProjection;
float4x4			World;

SamplerState		samplerTrilinear;
TextureCube			skyboxCubeMap;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float2 uv					: uv;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float3 worldPosition		: position;
	float2 uv					: uv;
	float4 position				: SV_POSITION;
};

//----------------------------------------------------------------------------
VertexToFragment VS_main (ApplicationToVertex app2vs)
{
	VertexToFragment vtf = (VertexToFragment)0;

	vtf.worldPosition = mul(float4(app2vs.position.xyz, 1.0), World).xyz;
	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
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

	final.color = float4( skyboxCubeMap.Sample(samplerTrilinear, vtf.worldPosition).xyz , 1.0f);

	return final;
}

//-------------------------------------------------------------------------------------------------
// Calculates the angle between two vectors
//-------------------------------------------------------------------------------------------------
float AngleBetween(in float3 dir0, in float3 dir1)
{
	return acos(dot(dir0, dir1));
}

//-------------------------------------------------------------------------------------------------
// Uses the CIE Clear Sky model to compute a color for a pixel, given a direction + sun direction
//-------------------------------------------------------------------------------------------------
float3 CIEClearSky(in float3 dir, in float3 sunDir)
{
	float gamma = AngleBetween(dir, sunDir);
	float S = AngleBetween(sunDir, float3(0, 1, 0));
	float theta = AngleBetween(dir, float3(0, 1, 0));

	float cosTheta = cos(theta);
	float cosS = cos(S);
	float cosGamma = cos(gamma);

	float num = (0.91f + 10 * exp(-3 * gamma) + 0.45 * cosGamma * cosGamma) * (1 - exp(-0.32f / cosTheta));
	float denom = (0.91f + 10 * exp(-3 * S) + 0.45 * cosS * cosS) * (1 - exp(-0.32f));

	float lum = num / denom;

	// Clear Sky model only calculates luminance, so we'll pick a strong blue color for the sky
	const float3 SkyColor = float3(0.2f, 0.5f, 1.0f);
	const float3 SunColor = float3(1.0f, 0.8f, 0.3f) * 150;
	const float SunWidth = 0.05f;

	float3 color = SkyColor;

	uint EnableSun = 1;

	// Draw a circle for the sun
	[flatten]
	if (EnableSun)
		color = lerp(SunColor, SkyColor, saturate(abs(gamma) / SunWidth));

	return max(color * lum, 0);
}

FragmentToPixel SkyModelPS (VertexToFragment vtf)
{
	FragmentToPixel final;

	float3 dir = vtf.worldPosition;
	float3 Bias = float3(0.1, 0.1, 0.1);
	float3 SunDirection = float3(1.0, 1.0, 1.0);

	final.color = float4(CIEClearSky(dir, SunDirection) * Bias, 1.0f);

	return final;
}