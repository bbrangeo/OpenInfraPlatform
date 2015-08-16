//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

SamplerState		samplerLinear;
Texture2D<float4>	tex0;

//float time;
//float2 resolution;
//float2 mouse;

////////////////////////////////////////////////////////////////////////////
struct VertexToFragment
{
	float4 position				: SV_POSITION;
	float2 uv					: uv;
};

////////////////////////////////////////////////////////////////////////////
VertexToFragment VS_main (uint id : SV_VertexID)
{
	VertexToFragment vtf = (VertexToFragment)0;

    switch (id) 
	{
		case 0:
			vtf.position =  float4 (-1, 1, 0, 1);
			vtf.uv = float2(0, 1);
			break;
		case 1:
			vtf.position =  float4 (-1, -1, 0, 1);
			vtf.uv = float2(0, 0);
			break;
		case 2: 
			vtf.position = float4 (1, 1, 0, 1);
			vtf.uv = float2(1, 1);
			break;
		case 3: 
			vtf.position = float4 (1, -1, 0, 1);
			vtf.uv = float2(1, 0);
			break;
		default: 
			vtf.position = float4 (0, 0, 0, 0);
			vtf.uv = float2(0, 0);
			break;
    }

	return vtf;
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

float4 PS_main (VertexToFragment vtf) : SV_Target0
{
	float4 top		= float4(  40.0/255.0,  40.0/255.0,  40.0/255.0, 1.0 );
	float4 bottom	= float4( 153.0/255.0, 160.0/255.0, 163.0/255.0, 1.0 );

	return lerp(top, bottom, vtf.uv.y);
}