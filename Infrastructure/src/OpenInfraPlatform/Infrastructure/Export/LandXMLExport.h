/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_LandXMLExport_ac000b42_148b_4277_8274_ce62d37978e1_h
#define OpenInfraPlatform_Infrastructure_LandXMLExport_ac000b42_148b_4277_8274_ce62d37978e1_h

#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		BLUEINFRASTRUCTURE_API void exportAsLandXML(buw::DigitalElevationModel::Ptr digitalElevationModel,
			buw::AlignmentModel::Ptr alignmentModel,
			const std::string &filename);
	} // end namespace Infrastructure
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::Infrastructure::exportAsLandXML;
}

#endif // end define OpenInfraPlatform_Infrastructure_LandXMLExport_ac000b42_148b_4277_8274_ce62d37978e1_h