#version 420

uniform vec3				g_EyePosition;
uniform sampler1D			colorRamp;
uniform sampler2D			texDiffuseMap;
uniform bool				bTerrainTextured;
uniform bool				bTerrainUseColorRamp;
uniform bool				bTerrainDisplayIsoLines;
uniform vec2				heightRange;

in VertexToFragment
{
	vec4 position;
	vec3 worldPosition;
	vec3 worldNormal;
	vec2 uv;
	vec3 localPosition;
	float height;
} vtf;

//----------------------------------------------------------------------------
// Pixel Shader
//----------------------------------------------------------------------------

out vec4 FragColor;

void main ()
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
	
	if(bTerrainUseColorRamp && bTerrainTextured)
	{
		
		float range = (heightRange.y - heightRange.x);
		float t = (vtf.height + 0.5 * range) / range;
		vec3 diffuseMaterialColor = texture(colorRamp, t).xyz;

		vec2 uv = vtf.localPosition.xy / 300;
		vec3 diffuseMaterialColor2 = texture(texDiffuseMap, uv).xyz;
		vec3 diffuseMaterialColor3 = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor2;

		finalColor = 0.5 * diffuseMaterialColor + 0.5 * diffuseMaterialColor3;
	}
	
	else if(bTerrainUseColorRamp)
	{
		float range = (heightRange.y - heightRange.x);
		float t = (vtf.height + 0.5 * range) / range;
		
		finalColor = texture(colorRamp, t).rgb;
	}

	else if (bTerrainTextured)
	{
		vec2 uv = vtf.localPosition.xy / 300;
		vec3 diffuseMaterialColor = texture(texDiffuseMap, uv).xyz;
		finalColor = (diffuseFactor * 0.8 + specular * 0.2 + ambientFactor) * diffuseMaterialColor;
	}
	
	if(bTerrainDisplayIsoLines)
	{
		float gridSize = 1;			// in worldSpace
		float gridWidth = 1;		// in Pixels 
		
		float f = abs(fract(vtf.height / gridSize + 0.5) - 0.5);
		float df = fwidth(vtf.height / gridSize);
		
		finalColor *= smoothstep( - gridWidth * df, gridWidth * df , f);
	}

	FragColor = vec4(finalColor, 1.0f);
}