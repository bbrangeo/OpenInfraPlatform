//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			WorldViewProjection;
float4x4			World;
float4x4			WorldIT;
float3				g_EyePosition;

Texture1D<float4>	colorRamp;
SamplerState		colorRampSampler;

Texture2D<float4>	texDiffuseMap;
SamplerState		sampler_;
bool				bTerrainTextured;
bool				bTerrainUseColorRamp;
bool 				bTerrainDisplayIsoLines;
float2				heightRange;

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
	float2 uv				    : uv;
	float3 localPosition        : position2;
	float  height               : height;
};


//----------------------------------------------------------------------------
VertexToFragment VS_main (ApplicationToVertex app2vs)
{
	VertexToFragment vtf = (VertexToFragment)0;

	vtf.height = app2vs.position.z;
	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.worldPosition = mul( float4(app2vs.position, 1), World ).xyz;
	vtf.worldNormal = mul(float4(app2vs.normal, 1.0), WorldIT).xyz;
	vtf.uv = app2vs.uv;
	vtf.localPosition = app2vs.position;

	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

float4 PS_main (VertexToFragment vtf, bool frontFace : SV_IsFrontFace) 	: SV_Target0
{
	float3 normal = normalize(vtf.worldNormal);
	
	if(!frontFace)
	{
		normal = -normal;
	}
	
	float3 light = normalize(g_EyePosition.xyz - vtf.worldPosition);

	// diffuse light
	float diffuseFactor = max(0, dot(light, normal));

	// specular light
	float3 eye = normalize( g_EyePosition.xyz - vtf.worldPosition);
	float3 vhalf = normalize(light + eye);
	float specular = max(0, dot(normal, vhalf));
	float Shininess = 20.0f;
	specular = pow(specular, Shininess);

	// ambient light
	float ambientFactor = 0.2;
	float3 color = float3(0.7, 0.7, 0.7);
	float3 finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * color;// * color;

	if(bTerrainUseColorRamp && bTerrainTextured)
	{
		float range = (heightRange.y - heightRange.x);
		float t = (vtf.height + 0.5 * range) / range;
		float3 diffuseMaterialColor = colorRamp.Sample(colorRampSampler, t).xyz;

		float2 uv = vtf.localPosition.xy / 300;
		float3 diffuseMaterialColor2 = texDiffuseMap.Sample(sampler_, uv, float2(0, 0)).xyz;
		float3 diffuseMaterialColor3 = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor2;

		finalColor = float3( 0.5 * diffuseMaterialColor + 0.5 * diffuseMaterialColor3);
	}
	
	else if(bTerrainUseColorRamp)
	{
		float range = (heightRange.y - heightRange.x);
		float t = (vtf.height + 0.5 * range) / range;
		
		finalColor = colorRamp.Sample(colorRampSampler, t).xyz;
	}
	
	else if (bTerrainTextured)
	{
		float2 uv = vtf.localPosition.xy / 300;
		float3 diffuseMaterialColor = texDiffuseMap.Sample(sampler_, uv, float2(0, 0)).xyz;
		finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor;
	}

	if(bTerrainDisplayIsoLines)
	{
		float gridSize = 1;			// in worldSpace
		float gridWidth = 1;		// in Pixels 
		
		float f = abs(frac(vtf.height / gridSize + 0.5) - 0.5);
		float df = fwidth(vtf.height / gridSize);
		
		finalColor *= smoothstep( - gridWidth * df, gridWidth * df , f);
	}
	
	return float4(finalColor, 1.0f);	
}