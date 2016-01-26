#include "OpenInfraPlatform/DataManagement/HeightmapImport.h"

#include <iostream>
#include "buw.BlueEngine.h"

OpenInfraPlatform::DataManagement::HeightmapImport::HeightmapImport(const std::string& filename, const buw::vector3d& offsetViewArea) :
	buw::Import(filename)
{
	buw::ReferenceCounted<buw::Image_4f> heightmap = buw::loadImageFromFile<buw::Image_4f>(filename.c_str());

	int totalIterations = heightmap->getHeight() * heightmap->getWidth() + (heightmap->getHeight() - 1) * (heightmap->getWidth() - 1);
	int iteration = 0;

	buw::ReferenceCounted<buw::Surface> s = std::make_shared<buw::Surface>();
	s->setName("Random terrain");

	buw::vector3d p;

	int verticesID = 0;

	float tileSize = 1;// td.tileSize;

	for (int y = 0; y < heightmap->getHeight(); y++)
		for (int x = 0; x < heightmap->getWidth(); x++)
		{
			float one = (float)x / 16;
			float two = (float)y / 16;
			float v = heightmap->getPixelColor(x, y).red();

			// Generating the vertex positions
			p = buw::vector3d(x * tileSize, y * tileSize, v * 16) + offsetViewArea;
			s->addPoint(p);

			iteration++;
		}

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