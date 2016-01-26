#include "OpenInfraPlatform/DataManagement/RandomTerrainImport.h"

#include <iostream>
#include "buw.BlueEngine.h"
#include "BlueFramework/Core/Perlin.h"

OpenInfraPlatform::DataManagement::RandomTerrainImport::RandomTerrainImport(const buw::terrainDescription& td, const buw::vector3d& offsetViewArea) :
	buw::Import("")
{
	/**
	Creating an instance of Perlin class

	@param octaves the number of octaves forming Perlin noise, it defines how noisy or smooth the function
	is. This is valid between 1 and 16.

	@param freq determines how many changes occur along a unit length, increasing the frequency will
	increase the number of terrain features. Reasonable values ranges from 1 to 8

	@param amp determines the range of output values. Setting it to 1 will return values between -1 and 1.

	@param seed it is the random number seed. This number causes the Perlin instance to be deterministic.
	*/
	buw::Perlin *perlin = new buw::Perlin(td.noOfOctaves, td.noiseFrequency, 1, 94);

	buw::ReferenceCounted<buw::Image_3f> heightmap = std::make_shared<buw::Image_3f>(td.terrainSize, td.terrainSize);

	int totalIterations = heightmap->getHeight() * heightmap->getWidth() + (heightmap->getHeight() - 1) * (heightmap->getWidth() - 1);
	int iteration = 0;


	buw::ReferenceCounted<buw::Surface> s = std::make_shared<buw::Surface>();
	s->setName("Random terrain");

	buw::vector3d p;

	int verticesID = 0;

	float tileSize = td.tileSize;

	for (int y = 0; y < heightmap->getHeight(); y++)
		for (int x = 0; x < heightmap->getWidth(); x++)
		{
			float one = (float)x / 16;
			float two = (float)y / 16;
			float v = (perlin->perlin_noise_2D(one, two) + 1) / 2;
			heightmap->setPixelColor(x, y, buw::color3f(v, v, v));

			// Generating the vertex positions
			p = buw::vector3d(x * tileSize, y * tileSize, v * 16) + offsetViewArea;
			s->addPoint(p);

			iteration++;
		}

	delete perlin; // free memory

	// Generating the triangle indicies
	for (int y = 0; y < heightmap->getHeight() - 1; y++)
	{
		for (int x = 0; x < heightmap->getWidth() - 1; x++)
		{
			float a = x + y      * heightmap->getWidth();
			float b = x + (y + 1) * heightmap->getWidth();
			float c = (x + 1) + y	    * heightmap->getWidth();

			buw::vector3i indicies(a, b, c);
			s->addTriangle(indicies);

			a = (x + 1) + y		 * heightmap->getWidth();
			b = x + (y + 1)	 * heightmap->getWidth();
			c = (x + 1) + (y + 1)	 * heightmap->getWidth();

			buw::vector3i indicies2(a, b, c);
			s->addTriangle(indicies2);

			iteration++;
		}
	}

	digitalElevationModel_->addSurface(s);
}