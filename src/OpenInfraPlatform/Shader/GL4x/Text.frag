//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

#version 420

uniform sampler2D font_map;

in VertexToFragment
{
	vec4 position;
	vec2 uv;
} vtf;

out vec4 FragColor;

void main()
{
	float smoothness = 64.0;
	float gamma = 2.2;

	// retrieve signed distance
	float sdf = texture( font_map, vec2(vtf.uv.x, 1.0-vtf.uv.y) ).r;

	// perform adaptive anti-aliasing of the edges
	float w = clamp( smoothness * (abs(dFdx(vtf.uv.x)) + abs(dFdy(1-vtf.uv.y))), 0.0, 0.5);
	float a = smoothstep(0.5-w, 0.5+w, sdf);

	// gamma correction for linear attenuation
	a = pow(a, 1.0/gamma);

	FragColor = vec4(vec3(1, 1, 1),a);
}