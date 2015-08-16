//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

#version 420

uniform vec3 g_EyePosition;

in VertexToFragment
{
	vec3 worldPosition;
	vec3 color;
	vec3 worldNormal;
} vtf;

out vec4 FragColor;

void main()
{
	vec3 normal = normalize(vtf.worldNormal);

	if (!gl_FrontFacing) 
	{
		normal = -normal;
	}
	
	vec3 light = normalize(g_EyePosition.xyz - vtf.worldPosition);

	// diffuse light
	float diffuseFactor = max(0, dot(light, normal));

	// specular light
	vec3 eye = normalize( g_EyePosition.xyz - vtf.worldPosition);
	vec3 vhalf = normalize(light + eye);
	float specular = max(0, dot(normal, vhalf));
	float Shininess = 20.0f;
	specular = pow(specular, Shininess);

	// ambient light
	float ambientFactor = 0.2;
	vec3 color = vtf.color; // float3(0.7, 0.7, 0.7);
	vec3 finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * color;// * color;
	
	FragColor = vec4(finalColor, 1.0f);
}