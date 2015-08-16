float4x4			World;
float4x4			View;
float4x4			Projection;
float4x4			WorldViewProjection;

float2				Viewport;			// x = width, y = height
float4				Positions[4];
float4				Frustum;			// x = NearPlaneWidth, y = NearPlaneHeight, z = NearPlaneDistance, w = FarPlaneDistance

bool				ortho;

//----------------------------------------------------------------------------
struct ApplicationToVertex
{
	float3 position				: position;
	float3 color				: color;
	float  size				    : size;
};

//----------------------------------------------------------------------------
struct VertexToGeometry
{
	float4 position		: position;
	float3 color		: color;
	float  size			: size;
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

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.color = app2vs.color;
	vtf.size = app2vs.size;

	return vtf;
}

//----------------------------------------------------------------------------
// Geometry Shader
//----------------------------------------------------------------------------

// From window pixel pos to projection frame at the specified z (view frame). 
float2 projToWindow(in float4 pos)
{
	return float2(  Viewport.x * 0.5 * ((pos.x/pos.w) + 1) ,
					Viewport.y * 0.5 * (1-(pos.y/pos.w)));
}

// From window pixel pos to projection frame at the specified z (view frame). 
float4 windowToProj(in float2 pos, float depth)
{
	return float4(  (((pos.x)*2/Viewport.x)-1)*depth,
					(((pos.y)*2/Viewport.y)-1)*(-depth),
					(depth - Frustum.z)*Frustum.w /(Frustum.w - Frustum.z),
					depth );
}

// Make a a ribbon line of the specified pixel width from 2 points in the projection frame.
void makeLine(out float4 points[4], in float4 posA, in float4 posB, in float width)
{
	// Bring A and B in window space
	float2 Aw = projToWindow(posA);
	float2 Bw = projToWindow(posB);

	// Compute tangent and binormal of line AB in window space
	// Binormal is scaled by line width 
	float2 tangent = normalize(Bw.xy - Aw.xy);
	float2 binormal = 0.5 * width * float2(tangent.y, -tangent.x);
	
	// Compute the corners of the ribbon in window space
	float2 A1w = (Aw - binormal);
	float2 A2w = (Aw + binormal);
	float2 B1w = (Bw - binormal);
	float2 B2w = (Bw + binormal);

	// bring back corners in projection frame
	points[0] = windowToProj(A1w, posA.w);
	points[1] = windowToProj(A2w, posA.w);
	points[2] = windowToProj(B1w, posB.w);
	points[3] = windowToProj(B2w, posB.w);
}

[maxvertexcount(6)]
void GS_main( line VertexToGeometry input[2], inout TriangleStream<GeometryToFragment> outStream )
{
	if (ortho == true)
	{
		float4 p0 = input[0].position;
		float4 p1 = input[1].position;

		float w0 = p0.w;
		float w1 = p1.w;

		p0.xyz /= p0.w;
		p1.xyz /= p1.w;

		float3 line01 = p1.xyz - p0.xyz;
		float3 dir = normalize(line01);

		// scale to correct window aspect ratio
		float3 ratio = float3(Viewport.y, Viewport.x, 0);
		ratio = normalize(ratio);

		float3 unit_z = normalize(float3(0, 0, -1));

		float3 normal = normalize(cross(unit_z, dir) * ratio);

		float width = 1.0 / Viewport.y * input[0].size;

		GeometryToFragment v[4];

		float3 dir_offset = dir * ratio * width;
		float3 normal_scaled = normal * ratio * width;

		float3 p0_ex = p0.xyz - dir_offset;
		float3 p1_ex = p1.xyz + dir_offset;

		v[0].position = float4(p0_ex - normal_scaled, 1) * w0;
		v[0].color = input[0].color;

		v[1].position = float4(p0_ex + normal_scaled, 1) * w0;
		v[1].color = input[0].color;

		v[2].position = float4(p1_ex + normal_scaled, 1) * w1;
		v[2].color = input[0].color;

		v[3].position = float4(p1_ex - normal_scaled, 1) * w1;
		v[3].color = input[0].color;

		outStream.Append(v[2]);
		outStream.Append(v[1]);
		outStream.Append(v[0]);

		outStream.RestartStrip();

		outStream.Append(v[3]);
		outStream.Append(v[2]);
		outStream.Append(v[0]);

		outStream.RestartStrip();
	}
	else
	{
		GeometryToFragment output;

		output.color = input[0].color;

		float4 lineCorners[4];
		float width = input[0].size;
		makeLine(lineCorners, input[0].position, input[1].position, width);

		output.position = lineCorners[0];
		outStream.Append( output );
	
		output.position = lineCorners[1];
		outStream.Append( output );
 
		output.position = lineCorners[2];
		outStream.Append( output );
	
		output.position = lineCorners[3];
		outStream.Append( output );
	
		outStream.RestartStrip();
	}
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