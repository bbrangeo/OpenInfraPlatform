//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

#version 420

uniform vec3				g_EyePosition;
uniform sampler2D			texDiffuseMap;
uniform bool				bTextured;

in VertexToFragment
{
	vec3 worldPosition;
	vec3 color;
	vec3 worldNormal;
	vec3 uv;
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
	float Shininess = 20.0;
	specular = pow(specular, Shininess);

	// ambient light
	float ambientFactor = 0.2;
	vec3 color = vec3(0.7, 0.7, 0.7);
	vec3 finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * color;// * color;
	
	if (bTextured)
	{
		float magic = 0.1;
		vec3 diffuseMaterialColor = texture(texDiffuseMap, vec2(vtf.uv.x, magic * vtf.uv.y)).xyz;
		finalColor =(diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor;
	}

	FragColor = vec4(finalColor, 1.0f);
}