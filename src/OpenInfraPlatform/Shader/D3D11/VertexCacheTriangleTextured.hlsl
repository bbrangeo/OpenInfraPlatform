//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			World;
float4x4			WorldIT;
float4x4			View;
float4x4			Projection;
float4x4			WorldViewProjection;
float3				g_EyePosition;
Texture2D<float4>	texDiffuseMap;
SamplerState		sampler_;
bool				bTextured;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float3 color				: color;
	float3 normal				: normal;
	float3 uv					: uv;
};

//----------------------------------------------------------------------------
struct VertexToFragment
{
	float4 position				: SV_POSITION; // vertex position 
	float3 worldPosition        : position;
	float3 color				: color;
	float3 worldNormal			: normal;
	float3 uv					: uv;
};

//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
VertexToFragment VS_main (ApplicationToVertex app2vs)
{
	VertexToFragment vtf = (VertexToFragment)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.worldPosition = mul( float4(app2vs.position, 1), World ).xyz;
	vtf.worldNormal = mul(float4(app2vs.normal, 1.0), WorldIT).xyz;	
	vtf.color = app2vs.color;
	vtf.uv = app2vs.uv;

	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------
float4 PS_main (VertexToFragment vtf, bool frontFace : SV_IsFrontFace) : SV_TARGET
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
	float3 color = float3(1.0, 0, 0);
	float3 finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * color;// * color;
	
	if (bTextured)
	{
		float magic = 0.1;
		float3 diffuseMaterialColor = texDiffuseMap.Sample(sampler_, float2(vtf.uv.x, magic * vtf.uv.y)).xyz;
		return float4((diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor, 1);
	}

	return  float4(finalColor, 1.0f);
}