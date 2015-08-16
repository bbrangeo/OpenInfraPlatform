/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "OutputStreamLandXMLDataBuilder.h"

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createCrossSectPnt(const PropertySet& parameters)
{
	out << "CrossSectPnt" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createDesignCrossSectSurf(const PropertySet& parameters)
{
	out << "DesignCrossSectSurf" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createCrossSectionSurf(const PropertySet& parameters)
{
	out << "CrossSectionSurf" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createSurface(const PropertySet& parameters, 
	const LandXMLSurface& surface)
{
	out << "Surface" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}

	out << "point count " << surface.getPointCount() << std::endl;
	out << "triangle count " << surface.getTriangleCount() << std::endl;
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createCircCurve(const PropertySet& parameters)
{
	out << "CircCurve" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createParaCurve(const PropertySet& parameters)
{
	out << "ParaCurve" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createPVI(const PropertySet& parameters)
{
	out << "PVI" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createProfAlign(const PropertySet& parameters)
{
	out << "ProfAlign" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createSpiral(const PropertySet& parameters)
{
	out << "Spiral" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createCurve(const PropertySet& parameters)
{
	out << "Curve" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createLine(const PropertySet& parameters)
{
	out << "Line" << std::endl;
	if (!parameters.isEmpty())
	{
		out << parameters;
	}
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createCoordGeom()
{
	out << "CoordGeom" << std::endl;
}

void OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::createAlignment(const PropertySet& parameters)
{
	out << "Alignment" << std::endl;
	out << parameters;
}

OpenInfraPlatform::Infrastructure::OutputStreamLandXMLDataBuilder::OutputStreamLandXMLDataBuilder(std::ostream& out) :
out(out)
{

}
