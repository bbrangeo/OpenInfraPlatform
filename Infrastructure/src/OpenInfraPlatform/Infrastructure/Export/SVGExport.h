/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author	    Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_SVGConverter_2e07ac2c_c8dd_46cb_a537_ae365e9b31d8_h
#define OpenInfraPlatform_Infrastructure_SVGConverter_2e07ac2c_c8dd_46cb_a537_ae365e9b31d8_h

#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include "buw.BlueCore.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/DigitalElevationModel.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "BlueFramework/ImageProcessing/color.h"
#include "BlueFramework/Core/Math/vector.h"
#include <boost/noncopyable.hpp>
#include <map>
#include <list>
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		//! SVG Exporter for alignments
		class BLUEINFRASTRUCTURE_API SVGExport
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(SVGExport);

			SVGExport();

			void convert(std::vector<buw::IAlignment3D::Ptr> alignments, 
				OpenInfraPlatform::Infrastructure::DigitalElevationModel::Ptr digitalElevationModel_, 
				const std::string& filename);

		private:
			void addPath(FILE *fp, const buw::vector2d& a, const buw::vector2d& b, const buw::vector2d& c);

			void outputToSVG(FILE *fp, buw::HorizontalAlignment2D::Ptr horizontalAlignment);
		}; // end class SVGExport
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::SVGExport;
}

#endif // end define OpenInfraPlatform_Infrastructure_SVGConverter_2e07ac2c_c8dd_46cb_a537_ae365e9b31d8_h
