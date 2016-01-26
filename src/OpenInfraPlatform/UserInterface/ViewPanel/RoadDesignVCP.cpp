/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "RoadDesignVCP.h"

void OpenInfraPlatform::UserInterface::RoadDesignVCP::drawPointE(const buw::vector3d& position, const buw::vector3d& offset)
{
	drawPoint(position - offset);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCP::drawPointE(const buw::vector2d& position, const buw::vector2d& offset)
{
	drawPoint(position - offset);
}

void OpenInfraPlatform::UserInterface::RoadDesignVCP::drawPointXZ(const buw::vector2d& position)
{
	drawPoint(position.x(), 0, position.y());
}

void OpenInfraPlatform::UserInterface::RoadDesignVCP::drawPointXZ(const double x, const double y)
{
	drawPointXZ(buw::vector2d(x, y));
}

void OpenInfraPlatform::UserInterface::RoadDesignVCP::drawPointsXZ(const std::vector<buw::vector2d>& points)
{
	for (int i = 0; i < points.size(); i++)
	{
		drawPointXZ(points[i]);
	}
}

OpenInfraPlatform::UserInterface::RoadDesignVCP::RoadDesignVCP(buw::ReferenceCounted<buw::IRenderSystem> renderer, const BlueFramework::Core::String& filename, const int maxPointCount) :VertexCachePoint(renderer, filename, maxPointCount)
{

}

OpenInfraPlatform::UserInterface::RoadDesignVCP::RoadDesignVCP(buw::ReferenceCounted<buw::IRenderSystem> renderer, const BlueFramework::Core::String& filename) : VertexCachePoint(renderer, filename)
{

}
