#include "VertexCacheLineAlignment.hlsl"


//----------------------------------------------------------------------------
struct VertexToGeometryAlignmentPick
{
	float4 position		: position;
	float  size			: size;
	uint   id			: id;
};

//----------------------------------------------------------------------------
struct GeometryToFragmentAlignmentPick
{
	float4 position				: SV_POSITION;
	uint id						: id;
};

//----------------------------------------------------------------------------
// Vertex Shader
//----------------------------------------------------------------------------
VertexToGeometryAlignmentPick VS_main_AlignmentPick(ApplicationToVertexAlignment app2vs)
{
	VertexToGeometryAlignmentPick vtf = (VertexToGeometryAlignmentPick)0;

	vtf.position = mul(float4(app2vs.position.xyz, 1.0), WorldViewProjection);
	vtf.id = app2vs.id;
	vtf.size = app2vs.size * 5;

	return vtf;
}

[maxvertexcount(6)]
void GS_main_AlignmentPick(line VertexToGeometryAlignmentPick input[2], inout TriangleStream<GeometryToFragmentAlignmentPick> outStream)
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

		GeometryToFragmentAlignmentPick v[4];

		float3 dir_offset = dir * ratio * width;
		float3 normal_scaled = normal * ratio * width;

		float3 p0_ex = p0.xyz - dir_offset;
		float3 p1_ex = p1.xyz + dir_offset;

		v[0].position = float4(p0_ex - normal_scaled, 1) * w0;
		v[0].id = input[0].id;

		v[1].position = float4(p0_ex + normal_scaled, 1) * w0;
		v[1].id = input[0].id;

		v[2].position = float4(p1_ex + normal_scaled, 1) * w1;
		v[2].id = input[0].id;

		v[3].position = float4(p1_ex - normal_scaled, 1) * w1;
		v[3].id = input[0].id;

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
		GeometryToFragmentAlignmentPick output;

		output.id = input[0].id;

		float4 lineCorners[4];
		float width = input[0].size;
		makeLine(lineCorners, input[0].position, input[1].position, width);

		output.position = lineCorners[0];
		outStream.Append(output);

		output.position = lineCorners[1];
		outStream.Append(output);

		output.position = lineCorners[2];
		outStream.Append(output);

		output.position = lineCorners[3];
		outStream.Append(output);

		outStream.RestartStrip();
	}
}

FragmentToPixel PS_main_AlignmentPick(GeometryToFragmentAlignmentPick gtf)
{
	FragmentToPixel final;

	final.color = float4(gtf.id / 117.0, 0, 0, 0);

	return final;
}