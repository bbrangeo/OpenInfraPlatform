//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

#version 420

in GeometryToFragment
{
	vec4 position;
	vec3 color;
} gtf;

out vec4 FragColor;

void main()
{
	FragColor = vec4(gtf.color, 1.0f);
}