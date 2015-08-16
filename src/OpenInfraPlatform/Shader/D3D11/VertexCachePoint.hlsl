//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------

float4x4			World;
float4x4			View;
float4x4			Projection;

SamplerState		samplerLinear;
Texture2D<float4>	texDiffuseMap;

float4				Viewport;			// x = width, y = height
float4				Positions[4];

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float3 color				: color;
	float  size				    : size;
};

/////////////////////////////////////////////////////////////////////////////
struct VertexToGeometry
{
	float3 worldPosition		: position;
	float3 color				: color;
	float  size				    : size;
};

//----------------------------------------------------------------------------
struct GeometryToFragment
{
	float4 position				: SV_POSITION;
	float3 color				: color;
};

//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
VertexToGeometry VS_main (ApplicationToVertex app2vs)
{
	VertexToGeometry vtf = (VertexToGeometry)0;

	vtf.worldPosition = mul(float4(app2vs.position.xyz, 1.0), World).xyz;
	vtf.color = app2vs.color;
	vtf.size = app2vs.size;

	return vtf;
}

//----------------------------------------------------------------------------
// Geometry Shader
//----------------------------------------------------------------------------
[maxvertexcount(4)]
void GS_main( point VertexToGeometry input[1], inout TriangleStream<GeometryToFragment> outStream )
{
	float g_pointSize = input[0].size;

	float fSizeX = (g_pointSize/Viewport.x)/4; //0.002;
	float fSizeY = (g_pointSize/Viewport.y)/4;

	GeometryToFragment output;

	for(int i=0; i<4; i++)
	{
		float4 outPos = mul( float4(input[0].worldPosition,1), View );
		output.position = mul( outPos, Projection);

		// ideal wäre wenn die pixel positon genau auf ein pixel-zentrum fallen würde
		float2 l_vCurrScreenPosition      = output.position.xy / output.position.w;
		float z = output.position.z / output.position.w;
		float2 l_vCurrPixelPosition       = l_vCurrScreenPosition * Viewport.xy * 0.5;
		int x = l_vCurrPixelPosition.x;
		int y = l_vCurrPixelPosition.y;
		l_vCurrPixelPosition.x = x + 0.5;// round(l_vCurrPixelPosition.x);
		l_vCurrPixelPosition.y = y + 0.5;//round(l_vCurrPixelPosition.y);

		// wie wärde die ideelae Bildschirmposition [0;1]?
		l_vCurrScreenPosition = l_vCurrPixelPosition * (1.0f / (Viewport.xy/2)) * output.position.w;

		// nochmal - jetzt idealle Positon verwenden, aber alte Tiefe beibehalten
		l_vCurrScreenPosition      = output.position.xy / output.position.w;
		output.position.xy = l_vCurrScreenPosition;
		output.position.w = 1;
		output.position.z = z;
		
		// Pixel nach der Projektion vergrößern auf gewünschte größe

		float zoverNear = 1;//(outPos.z)/g_ClipPlanes.x;
		fSizeX = 1/Viewport.x * 2 * g_pointSize;
		fSizeY = 1/Viewport.y * 2 * g_pointSize;
		float4 posSize = float4( Positions[i].x*fSizeX,
								 Positions[i].y*fSizeY,
								 0,
								 0 );
		

		output.position += posSize;
		output.color = input[0].color; //float3(204.0/255,204.0/255,204.0/255);

		outStream.Append(output);
	}
	outStream.RestartStrip();
}

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------
struct FragmentToPixel
{
	float4 color				: SV_Target0;
};

FragmentToPixel PS_main (GeometryToFragment gtf)
{
	FragmentToPixel final;

	final.color = float4(gtf.color, 1.0f);

	return final;
}