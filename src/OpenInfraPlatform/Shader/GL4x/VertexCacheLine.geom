//----------------------------------------------------------------------------
// Geometry Shader
//----------------------------------------------------------------------------

#version 420

uniform vec2 Viewport;			// x = width, y = height
uniform vec4 Frustum;
uniform bool ortho;

layout (lines) in;
layout (triangle_strip, max_vertices = 4) out;

in VertexToGeometry
{
	vec4 position;
	vec3 color;
	float size;
} inputG[2];
 
out GeometryToFragment
{
	vec4 position;
	vec3 color;
} outputG;

struct GeometryToFragmentEx
{
	vec4 position;
	vec3 color;
};

// From window pixel pos to projection frame at the specified z (view frame). 
vec2 projToWindow(in vec4 pos)
{
    return vec2(  Viewport.x*0.5*((pos.x/pos.w) + 1),
                  Viewport.y*0.5*(1-(pos.y/pos.w)));
}

// From window pixel pos to projection frame at the specified z (view frame). 
vec4 windowToProj(in vec2 pos, float depth)
{
    return vec4(  (((pos.x)*2/Viewport.x)-1)*depth,
                  (((pos.y)*2/Viewport.y)-1)*(-depth),
                  (depth - Frustum.z)*Frustum.w /(Frustum.w - Frustum.z),
                    depth );
}

// Make a a ribbon line of the specified pixel width from 2 points in the projection frame.
void makeLine(out vec4 points[4], in vec4 posA, in vec4 posB, in float width)
{
    // Bring A and B in window space
    vec2 Aw = projToWindow(posA);
    vec2 Bw = projToWindow(posB);

    // Compute tangent and binormal of line AB in window space
    // Binormal is scaled by line width 
    vec2 tangent = normalize(Bw.xy - Aw.xy);
    vec2 binormal = 0.5*width * vec2(tangent.y, -tangent.x);
    
    // Compute the corners of the ribbon in window space
    vec2 A1w = (Aw - binormal);
    vec2 A2w = (Aw + binormal);
    vec2 B1w = (Bw - binormal);
    vec2 B2w = (Bw + binormal);

    // bring back corners in projection frame
    points[0] = windowToProj(A1w, posA.w);
    points[1] = windowToProj(A2w, posA.w);
    points[2] = windowToProj(B1w, posB.w);
    points[3] = windowToProj(B2w, posB.w);
}

void main()
{
	if (ortho == true)
	{
		vec4 p0 = inputG[0].position;
		vec4 p1 = inputG[1].position;

		float w0 = p0.w;
		float w1 = p1.w;

		p0.xyz /= p0.w;
		p1.xyz /= p1.w;

		vec3 line01 = p1.xyz - p0.xyz;
		vec3 dir = normalize(line01);

		// scale to correct window aspect ratio
		vec3 ratio = vec3(Viewport.y, Viewport.x, 0);
		ratio = normalize(ratio);

		vec3 unit_z = normalize(vec3(0, 0, -1));

		vec3 normal = normalize(cross(unit_z, dir) * ratio);

		float width = 1.0 / Viewport.y * inputG[0].size;

		GeometryToFragmentEx v[4];

		vec3 dir_offset = dir * ratio * width;
		vec3 normal_scaled = normal * ratio * width;

		vec3 p0_ex = p0.xyz - dir_offset;
		vec3 p1_ex = p1.xyz + dir_offset;

		v[0].position = vec4(p0_ex - normal_scaled, 1) * w0;
		v[0].color = inputG[0].color;

		v[1].position = vec4(p0_ex + normal_scaled, 1) * w0;
		v[1].color = inputG[0].color;

		v[2].position = vec4(p1_ex + normal_scaled, 1) * w1;
		v[2].color = inputG[0].color;

		v[3].position = vec4(p1_ex - normal_scaled, 1) * w1;
		v[3].color = inputG[0].color;

		gl_Position = v[2].position;
		outputG.position =  v[2].position;
		outputG.color = v[2].color;
		EmitVertex();

		gl_Position = v[1].position;
		outputG.position =  v[1].position;
		outputG.color = v[1].color;
		EmitVertex();

		gl_Position = v[0].position;
		outputG.position =  v[0].position;
		outputG.color = v[0].color;
		EmitVertex();

		EndPrimitive();

		gl_Position = v[3].position;
		outputG.position =  v[3].position;
		outputG.color = v[3].color;
		EmitVertex();

		gl_Position = v[2].position;
		outputG.position =  v[2].position;
		outputG.color = v[2].color;
		EmitVertex();

		gl_Position = v[0].position;
		outputG.position =  v[0].position;
		outputG.color = v[0].color;
		EmitVertex();

		EndPrimitive();
	}
	else
	{
		outputG.color = inputG[0].color;

		vec4 lineCorners[4];
		float width = inputG[0].size;
		vec4 xx = inputG[0].position;
		makeLine(lineCorners, inputG[0].position, inputG[1].position, width);

		outputG.position = lineCorners[0];
		gl_Position = outputG.position;
		EmitVertex();
    
		outputG.position = lineCorners[1];
		gl_Position = outputG.position;
		EmitVertex();
 
		outputG.position = lineCorners[2];
		gl_Position = outputG.position;
		EmitVertex();
    
		outputG.position = lineCorners[3];
		gl_Position = outputG.position;
		EmitVertex();
    
		EndPrimitive();
	}
}