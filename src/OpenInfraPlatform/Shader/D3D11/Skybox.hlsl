float4x4		View;
float4x4		Projection;
float3			Bias;
float3			SunDirection;
uint			EnableSun;

//=================================================================================================
// Input/Output structs
//=================================================================================================

struct VSInput
{
    float3 PositionOS : POSITION;
};

struct VSOutput
{
    float4 PositionCS 	: SV_Position;
    float3 TexCoord 	: TEXCOORD;
    float3 Bias 		: BIAS;
};

//=================================================================================================
// Vertex Shader
//=================================================================================================
VSOutput VS_main(in VSInput input)
{
    VSOutput output;

    // Rotate into view-space, centered on the camera
    float3 positionVS = mul(input.PositionOS.xyz, (float3x3)View);

    // Transform to clip-space
    output.PositionCS = mul(float4(positionVS, 1.0f), Projection);

    // Make a texture coordinate
    output.TexCoord = input.PositionOS;

    // Pass along the bias
    output.Bias = Bias;

    return output;
}

//=================================================================================================
// Pixel Shader
//=================================================================================================

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

	// Draw a circle for the sun
	[flatten]
	if (EnableSun)
		color = lerp(SunColor, SkyColor, saturate(abs(gamma) / SunWidth));

	return max(color * lum, 0);
}

//=================================================================================================
// Sky Model Pixel Shader
//=================================================================================================
float4 PS_main(in VSOutput input) : SV_Target
{
	float3 dir = normalize(input.TexCoord);
	
	return float4(CIEClearSky(dir, SunDirection) * input.Bias, 1.0f);
}